%{
#include "controller.h"

int yylex();
int yyparse();

void yyerror(const char *str){fprintf(stderr,"error: %s\n",str);}

int yywrap(){return 1;}
%}
%union
{
        int number;
        char* string;
}

%token ADD STATUS TURN QUIT SET
%token <number> NUMBER
%token <string> BUILDING
%token <string> ONOFF

%%
commands: /* epsilon rule */
        | commands command
		| commands error
        ;
command:
        add_building
		| get_building_status
		| turn_off_on
		| quit
		| set_temperature
        ;
add_building:
        ADD BUILDING
        {
            strcpy(building_list[current_building_index].name, $2);
			building_list[current_building_index].temperature = 65;
			strcpy(building_list[current_building_index].on_off, "off");
			current_building_index = current_building_index + 1;
			printf("\t'%s' added!\n",$2);
        }
        ;
get_building_status:
        STATUS BUILDING
        {
            find_building_data($2);
        }
	;
turn_off_on:
		TURN BUILDING ONOFF
		{
			set_building_status($2, $3);
		}
	;
quit:
	QUIT
		{
			exit(0);
		}
	;
set_temperature:
	SET BUILDING NUMBER
	{
		 if (set_building_temperature($2, $3) == 1)
			{
				printf("\t'%s' is set to '%d'\n", $2, $3);
			}
			else
			{
					printf("\t'did not find %s'\n", $2);
			}
	}
	;
%%
