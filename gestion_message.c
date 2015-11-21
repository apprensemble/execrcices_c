#include "gestion_message.h"
#include <string.h>
static char message[256];
int set_message(char nouveau_message[256]) {
  strcpy(message,nouveau_message);
}
char* get_message () {
  return message;

}
