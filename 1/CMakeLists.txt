
add_executable(generator occ-generetor-main.cc occ.cc Generator.cc A/I/Parser/Generator-AI.cc A/I/Parser/declarartion.cc A/I/Parser/functions.cc A/I/Parser/rules.cc A/I/Parser/rules-instructions.cc       A/I/Lexer/Generator-AI.cc A/I/Lexer/declarartion.cc A/I/Lexer/functions.cc A/I/Lexer/rules.cc)
add_custom_target(generator-v1 COMMAND make -f OCC-v1.mk TARGET_OUTPUT_DIR=$(TARGET_OUTPUT_DIR) all DEPENDS generator)

