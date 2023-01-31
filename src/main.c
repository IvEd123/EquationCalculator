#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "defines.h"

#include "tree.h"
#include "functions.h"
#include "tree_functions.h"
#include "Solution.h"

float calculate_equation(char* raw_input) {
	char** parsed_symbols_array;
	int parsed_symbols_num;
	token* token_array;

	//devide input string to array of symbols 
	if ((parsed_symbols_array = parse_input_string(raw_input, strlen(raw_input), &parsed_symbols_num)) == 0)
		return -1;

	//parse symbols
	if ((token_array = lexer(parsed_symbols_array, parsed_symbols_num)) == 0)
		return -1;

	int error_code = check_syntax_errors(token_array, parsed_symbols_num);
	if (error_code != 0)
		return -1;

	//build tree from array of tokens
	node* root = build_tree(token_array, parsed_symbols_array, parsed_symbols_num);

	//find root of equation
	float result = solve(root);


	delete_node(root);
	for(int i = 0; i < parsed_symbols_num; i++)
		free(parsed_symbols_array[i]);
	free(parsed_symbols_array);
	free(token_array);


	return result;
}

int main(int argc, char** argv) {



	char* raw_input = (char*)malloc(MAX_STR_LENGTH);

	printf("Enter expression:\n");

	fgets(raw_input, MAX_STR_LENGTH, stdin);

	if (raw_input[0] == '\n') {
		printf("Empty string\n");
		return -1;
	}	

	float result = calculate_equation(raw_input);

	printf("\nResult: %f\n", result);

	free(raw_input);

	return 0;
}

