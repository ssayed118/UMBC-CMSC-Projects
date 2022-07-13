#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
        char name[64];
        int temperature;
        char on_off[64];
} building_type;

building_type building_list[128];

int current_building_index = 0;

building_type find_building_data(char* buildingname)
{
        building_type data;
	int found_it = 0;
        for (int i = 0; i < current_building_index; i++)
        {
                if (strcmp(building_list[i].name, buildingname) == 0)
                {
                        data = building_list[i];
			printf("\t   building:  %s\n", data.name);
                        printf("\t     status:  %s\n", data.on_off);
                        printf("\ttemperature:  %d\n", data.temperature);
			found_it = 1;
                }
        }
	if (found_it == 0)
	{
		printf("\t'did not find %s'\n", buildingname);
	}
        return data;
}

int set_building_status(char* buildingname, char* onoff)
{
        int result = 0;
        for (int i = 0; i < current_building_index; i++)
        {
                if (strcmp(building_list[i].name, buildingname) == 0)
                {
                        strcpy(building_list[i].on_off, onoff);
                        result = 1;
			printf("\t'%s' is '%s'\n", buildingname, onoff);
                }
        }
	if(result == 0)
	  printf("\t'did not find %s'\n", buildingname);
        return result;
}

int set_building_temperature(char* buildingname, int temperature)
{
        int result = 0;
        for (int i = 0; i < current_building_index; i++)
        {
                if (strcmp(building_list[i].name, buildingname) == 0)
                {
                        building_list[i].temperature = temperature;
                        result = 1;
                }
        }
        return result;
}
