
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


#include <iostream>
#include <string.h>

#include "Generator.hh"

namespace occ = oct::cc::v1;

occ::Language language(const std::string& lang);
bool lexer();
bool parser();

std::filesystem::path outpath;
std::string lang,comp;

int main (int argc, char* argv[])
{

	for(size_t i = 1; i < (size_t)argc; i++)
	{
		if(strcmp(argv[i],"--output") == 0)
		{
			outpath = argv[++i];
		}
		else if(strcmp(argv[i],"--lang") == 0)
		{
			lang = argv[++i];
		}
		else if(strcmp(argv[i],"--comp") == 0)
		{
			comp = argv[++i];
		}
		else
		{
		    std::cout << "Comando desconocido : " << argv[i] << "\n";
		}
	}

	if(comp.empty())
	{
		std::cerr << "Indique el Componente";
		return EXIT_FAILURE;
	}
	if(lang.empty())
	{
		std::cerr << "Indique el Lenguaje del Componente.";
		return EXIT_FAILURE;
	}

    if(comp.compare("lexer") == 0)
    {
        if(not lexer()) return EXIT_FAILURE;
    }
    else if(comp.compare("parser") == 0)
    {
        if(not parser()) return EXIT_FAILURE;
    }
    else
    {
        std::cerr << "Componente desconocido : " << comp << "\n";
    }

	return EXIT_SUCCESS;
}

occ::Language language(const std::string& lang)
{
    if(lang.compare("A") == 0 or lang.compare("AI") == 0) return occ::Language::AI;
    else if(lang.compare("AII") == 0 or lang.compare("A+") == 0) return occ::Language::AII;

    return occ::Language::none;
}
bool lexer()
{
    occ::Lexer generator(language(lang));
	if(outpath.empty())
    {
        generator.save(std::cout);
    }
    else
	{
        std::fstream outstream;

		if(std::filesystem::exists(outpath)) std::filesystem::remove(outpath);
        outstream.open(outpath,std::ios::app);
        if(not outstream.is_open())
        {
            std::cerr << "Fallo al abrir el archivo " << outpath << "\n";
            return false;
        }
        generator.save(outstream);
        outstream.flush();
        outstream.close();
	}

    return true;
}
bool parser()
{
    occ::Parser generator(language(lang));
	if(outpath.empty())
    {
        generator.save(std::cout);
    }
    else
	{
        std::fstream outstream;

		if(std::filesystem::exists(outpath)) std::filesystem::remove(outpath);
        outstream.open(outpath,std::ios::app);
        if(not outstream.is_open())
        {
            std::cerr << "Fallo al abrir el archivo " << outpath << "\n";
            return false;
        }
        generator.save(outstream);
        outstream.flush();
        outstream.close();
	}

	return true;
}
