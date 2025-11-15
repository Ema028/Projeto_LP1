#include <stdio.h>
#include <stdlib.h>

ssize_t getline(char** buffer, size_t* size, FILE* file) {
    size_t index = 0;
	int c;
	
	//cria um buffer caso ele seja nulo
    if (*buffer == NULL) {
        *size = 128;                       
        *buffer= malloc(*size);          
        if (*buffer == NULL){           
            return -1;
		}
    }

	//ler até EOF
    while ((c = fgetc(file)) != EOF) 
	{
		//realocar o buffer para um maior caso não tenha espaço suficiente
        if (index + 1 >= *size) 
		{
            size_t new_size;
			if (*size == 0){
				new_size = 128;
			}else{
				new_size *= 2;
			}

            char* new_buffer = realloc(buffer, new_size);
            if (new_buffer == NULL){
				return -1;
			}

            *buffer = new_buffer;
            *size = new_size;
        }

        (*buffer)[index++] = (char)c;

        if (c == '\n') //fim da linha
            break;
    }
	
	//caso seja um arquivo vazio
    if (index == 0 && c == EOF){
        return -1;
	}

    *buffer[index] = '\0';

    return index;
}
