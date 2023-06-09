
/*
 * Octetos Assembler
 * Copyright (C) 2022 Azael Reyes <azael.devel@gmail.com>
 *
 * Octetos Compuler Collection is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CC is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string.h>
#include <iostream>
#include <fstream>
#include <list>

#include "A-Driver.hh"
#include "A+-Driver.hh"

bool extension(const std::filesystem::path& path, const std::string& ext)
{
    //std::cout << "\n\n";
    if(ext.size() >= path.string().size()) return false;
    for(size_t i = 0; i < ext.size(); i++)
    {
        if(path.string()[path.string().size() - i - 1] != ext[ext.size() - i - 1]) return false;
        //std::cout << path.string()[path.string().size() - i - 1] << " == " << ext[ext.size() - i - 1] << "\n";
    }
    //std::cout << "El archivo " << path << ", tinen extecion '" << ext << "'\n";
    return true;
}

namespace AII_here = oct::cc::v0::AII;
namespace AI_here = oct::cc::v0::AI;
namespace cc_here = oct::cc::v0;

int main (int argc, char* argv[])
{
    std::fstream outstream;
    std::filesystem::path output_file;
    std::list<std::filesystem::path> inputs;
    core_here::Block block;
    std::string target_cpu_str,environment_str;
    cc_here::CPU target_cpu;
    cc_here::Environment environment;

	for(size_t i = 0; i < (size_t)argc; i++)
	{
		if(strcmp(argv[i],"--output-file") == 0)
		{
			output_file = argv[++i];
		}
		else if(strcmp(argv[i] , "--target-cpu") == 0)
		{
		    target_cpu_str = argv[++i];
			if(target_cpu_str.compare("intel-8086") == 0)
            {
                target_cpu = cc_here::CPU::intel_8086;
            }
            else
            {
                target_cpu = cc_here::CPU::none;
            }
		}
		else if(strcmp(argv[i] , "--environment") == 0)
		{
		    environment_str = argv[++i];
			if(environment_str.compare("freestanding") == 0)
            {
                environment = cc_here::Environment::freestanding;
            }
            else if(environment_str.compare("freestanding-boot") == 0)
            {
                environment = cc_here::Environment::freestanding_boot;
            }
            else
            {
                environment = cc_here::Environment::none;
            }
		}
		else if(strcmp(argv[i] , "--output-type") == 0)
		{

		}
		else if(argv[i][0] == '-')
		{
			std::cout << "Comando desconocido \"" <<  argv[i] << "\" \n";
		}
		else
		{//posibles archivos input
			inputs.push_back(argv[++i]);
		}
	}

	if(inputs.empty())
	{
		std::cout << "Indique almenos un archivo para compilar.";
		return EXIT_FAILURE;
	}
	if(output_file.empty())
	{
		std::cerr << "Indique el archivo de resultado.";
		return EXIT_FAILURE;
	}


	outstream.open(output_file, std::ios_base::out | std::ios_base::binary);
    if(not outstream.is_open())
    {
		std::cerr << "Fallo al abrir el archivo de resultado.";
		return EXIT_FAILURE;
    }

    if(target_cpu == cc_here::CPU::intel_8086)
    {
        //std::cout << "Compilando para intel 8086\n";
    }
    else
    {
        std::cerr << "Deve indicar el CPU objetivo";
		return EXIT_FAILURE;
    }
    if(environment == cc_here::Environment::freestanding or environment == cc_here::Environment::freestanding_boot )
    {
        std::cout << "Working on free-standing\n";
    }
    else
    {
        std::cerr << "Deve indicar el ambiente";
		return EXIT_FAILURE;
    }

    AI_here::SymbolTable symbols;
	AI_here::Tray<AI_here::nodes::translation_unit> trayI;
	AI_here::Tray<AII_here::nodes::external_declaration> trayII;
	trayI.symbols = &symbols;
	trayII.symbols = &symbols;
    AI_here::Driver driverI(trayI);
	AII_here::Driver driverII(trayII);
	for(const std::filesystem::path& path : inputs)
	{
	    if(not std::filesystem::exists(path))
        {
            std::cerr << "No existe el archivo fuente " << path << "\n";
            return EXIT_FAILURE;
        }

        //
        if(extension(path,".a.asm"))
        {
            //std::cout << "Parsing ...\n";
            std::cout << "Compilando " << path << " para intel 8086\n";
            if(driverI.parse(path))
            {
                if(not driverI.semantic())
                {

                }
                //std::cout << "Printing ...\n";
                driverI.print(std::cout);
                //std::cout << "Generating ...\n";
                driverI.generate(outstream);
                outstream.flush();
                outstream.close();
                std::cout << "\nCompletdo.\n";
            }
            else
            {
                std::cout << "\nError sintactico..\n";
            }
        }
        else if(extension(path,".a+.asm"))
        {
            //std::cout << "Parsing ...\n";
            std::cout << "Compilando " << path << " para intel 8086\n";
            if(driverII.parse(path))
            {
                if(not driverII.semantic())
                {

                }
                const AI_here::nodes::translation_unit* tree = driverII.translate();
                //std::cout << "Printing ...\n";
                //driverII.print(std::cout);
                //if(tree) driverI.print(std::cout,tree);
                //std::cout << "Generating ...\n";
                if(tree) driverI.generate(outstream,tree);
                outstream.flush();
                outstream.close();
                std::cout << "\nCompletdo.\n";
            }
        }
        else
        {
            //std::cerr << "El archivo " << path << ", no se reconoce como un archivo fuente.\n";
            std::cerr << "La extencion " << path.extension() << ", no se reconoce como un archivo fuente.\n";
        }
	}

	//symbols.generate_memory();
    //symbols.print();

    //std::cout << "sizeof(unsigned) = " << sizeof(unsigned) << "\n";
    //std::cout << "sizeof(signed) = " << sizeof(signed) << "\n";

	return EXIT_SUCCESS;
}

