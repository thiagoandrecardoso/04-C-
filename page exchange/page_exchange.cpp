#include <iostream>
#include <new>
#include <queue>

using namespace std;

queue<char> fila;
int page_faults = 0;
int string_position = 0;
#define NUMBER_OF_PAGES 4

void init_physical_memory(char *physical_memory, char reference_string[]);
bool has_pages_faults(char *physical_memory, char c);  
void refresh_memory(char *physical_memory, char new_char);
void print_physical_memory(char *physical_memory);

int main()
{
    char reference_string[] = {'2', '3', '1', 'a', 'b', '3', '1', '1', 'c', 'd', '1', 'a'};
    char *physical_memory = new (nothrow) char[NUMBER_OF_PAGES];

    init_physical_memory(physical_memory, reference_string);

    cout << "Memoria fisica inicial ";    
    print_physical_memory(physical_memory);
    cout << endl;

    for (int i = string_position; i < sizeof(reference_string)/sizeof(*reference_string); i++)
    {
        if (has_pages_faults(physical_memory, reference_string[i]))
        {
            page_faults++;
            refresh_memory(physical_memory, reference_string[i]);
            print_physical_memory(physical_memory);
            cout << endl;
        }
    }
    cout << "Numero de Pages Faults: " << page_faults << endl;
}

void init_physical_memory(char *physical_memory, char reference_string[])
{
    for (int i = 0; i < NUMBER_OF_PAGES; i++)
    {
        physical_memory[i] = reference_string[i];
        fila.push(reference_string[i]);
        page_faults++;
        string_position++;
    }
}

bool has_pages_faults(char *physical_memory, char c)
{
    bool has = true;
    for (int i = 0; i < NUMBER_OF_PAGES; i++)
    {
       if (physical_memory[i] == c)
       {   
           has = false;
       }
    }
    return has;
}

void refresh_memory(char *physical_memory, char new_char)
{
    for (int i = 0; i < NUMBER_OF_PAGES; i++)
    {
        if (physical_memory[i] == fila.front())
        {
            physical_memory[i] = new_char;
            fila.pop();
            fila.push(new_char);
            return;
        }
    }
}

void print_physical_memory(char *physical_memory)
{
    for (int i = 0; i < NUMBER_OF_PAGES; i++)
    {
        cout << " " << physical_memory[i] << "";
    }
}
