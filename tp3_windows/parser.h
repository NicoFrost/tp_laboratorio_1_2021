/*
 * parser.h
 *
 *  Created on: 8 nov. 2021
 *      Author: Javier
 */

#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include <string.h>

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee);
#endif /* PARSER_H_ */
