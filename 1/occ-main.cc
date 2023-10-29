
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

#include "A/I/Driver.hh"

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


namespace occ = oct::cc::v1;

int main (int argc, char* argv[])
{
    std::fstream outstream;
    std::filesystem::path output_file;
    std::list<std::filesystem::path> inputs;
    std::string target_cpu_str,environment_str;
    occ::CPU target_cpu;
    occ::Environment environment;

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
                target_cpu = occ::CPU::intel_8086;
            }
            else
            {
                target_cpu = occ::CPU::none;
            }
		}
		else if(strcmp(argv[i] , "--environment") == 0)
		{
		    environment_str = argv[++i];
			if(environment_str.compare("freestanding") == 0)
            {
                environment = occ::Environment::freestanding;
            }
            else if(environment_str.compare("freestanding-boot") == 0)
            {
                environment = occ::Environment::freestanding_boot;
            }
            else
            {
                environment = occ::Environment::none;
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

    if(target_cpu == occ::CPU::intel_8086)
    {
        //std::cout << "Compilando para intel 8086\n";
    }
    else
    {
        std::cerr << "Deve indicar el CPU objetivo";
		return EXIT_FAILURE;
    }
    if(environment == occ::Environment::freestanding or environment == occ::Environment::freestanding_boot )
    {
        std::cout << "Working on free-standing\n";
    }
    else
    {
        std::cerr << "Deve indicar el ambiente";
		return EXIT_FAILURE;
    }

    occ::SymbolTable<occ::Node> symbols;
	occ::Tray<occ::A::I::Unit,occ::Node> trayI;
	trayI.symbols = &symbols;
    occ::A::I::Driver driverI(trayI);
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

        }
        else
        {
            //std::cerr << "El archivo " << path << ", no se reconoce como un archivo fuente.\n";
            std::cerr << "La extencion " << path.extension() << ", no se reconoce como un archivo fuente.\n";
        }
	}


	return EXIT_SUCCESS;
}

