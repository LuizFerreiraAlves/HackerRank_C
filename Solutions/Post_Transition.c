#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;

void print_all_packages(town t) {
    printf("%s:\n", t.name);
    for(int office = 0; office < t.offices_count; ++office){
        printf("\t%d:\n", office);
        for(int package = 0; package < t.offices[office].packages_count; ++package){
            printf("\t\t%s\n", t.offices[office].packages[package].id);
        }
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {

    int packs_target, packs_source;

    //IMPORTANT: the number of packages_count varies during the for statement
    //This is why we need to decrement package_id at the end of this statement
    for(int package_id = 0; package_id < source->offices[source_office_index].packages_count; ++package_id){

        if( (source->offices[source_office_index].packages[package_id].weight >= 
           target->offices[target_office_index].min_weight) &&
            (source->offices[source_office_index].packages[package_id].weight <= 
           target->offices[target_office_index].max_weight) ) {

                packs_target = target->offices[target_office_index].packages_count;
                packs_source = source->offices[source_office_index].packages_count;
                 
                //Adding the package to the target (and reallocating memory)
                target->offices[target_office_index].packages = realloc(target->offices[target_office_index].packages,
                        (packs_target + 1)*sizeof(package));

                target->offices[target_office_index].packages[packs_target] = 
                    source->offices[source_office_index].packages[package_id];

                //Excluding the package from the source (and reallocating memory)
                int temp_id = package_id;
                while(temp_id < packs_source){
                    source->offices[source_office_index].packages[temp_id] = 
                    source->offices[source_office_index].packages[temp_id+1];
                    temp_id++;
                } 
                
                source->offices[source_office_index].packages = realloc(source->offices[source_office_index].packages, 
                        (packs_source - 1)*sizeof(package));

                //Modifying the number of packages of the target and the source offices
                target->offices[target_office_index].packages_count++;
                source->offices[source_office_index].packages_count--;
		
		//The package package_id actually is (package_id + 1) now because it was deleted from the source
		//Package (package_id + 1) receives (package_id + 2), (package_id + 2) receives (package_id + 3)...
		//So we need to check once again the package package_id so we decrement it here since it is added +1 in the for statement
                package_id--;
           }
    }	
}

town town_with_most_packages(town* towns, int towns_count) {
    town t = towns[0];
    int total_packages = 0, aux_total_packages = 0;
    for(int town = 0; town < towns_count; ++town){
        for(int office = 0; office < towns[town].offices_count; ++office){
            aux_total_packages += towns[town].offices[office].packages_count;
        }
        if(aux_total_packages > total_packages){
            total_packages = aux_total_packages;
            t = towns[town];
        }
        aux_total_packages = 0;
    }
    return t;
}

town* find_town(town* towns, int towns_count, char* name) {
    town* town_with_name;
    for(int t = 0; t < towns_count; ++t){
        if(strcmp(towns[t].name, name) == 0) town_with_name = &towns[t];
    }

    return town_with_name;
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}

