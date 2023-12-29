#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //Guardar log de los archivos
#define MAP_WIDTH 35
#define MAP_HEIGHT 20

//------------------------------------------------------------------------------------------
// ENTIDADES DEL JUEGO
//------------------------------------------------------------------------------------------

//Variables de los structs
struct playerEntity {
  char charName[30];
  int health;
  int maxHP;
  int strength;
  int iq;
  int speed;
  int luck;
  int posX;
  int posY;
  int posXgoal;
  int posYgoal;
}; typedef struct playerEntity Player;

struct enemyEntity {
  int hp;
  int posX;
  int posY;
}; typedef struct enemyEntity Enemy;

struct itemEntity {
  int isTaken;
  int posX;
  int posY;
}; typedef struct itemEntity Item;

//------------------------------------------------------------------------------------------
// INPUT E INTEGRIDAD DE ARCHIVOS
//------------------------------------------------------------------------------------------

//Extrae el valor numerico que se encuentra en un string.
//Sirve para asignar valores numericos al string.
int retrieveIntfromStr(char string[30]) {
  int i,numberRead=0;
  for(i=0;i<30;i++) {
    if ( (string[i] >= '0') && (string[i] <= '9') ) {
      numberRead=numberRead*10;
      numberRead=numberRead + (string[i]-'0');
    }
    else if ( (string[i] == '\n') || (string[i] == '\0') ) {
      break;
    }
  }
  return numberRead;
}

//Revisa si el input asignado es valido o no.
//Usa valores inclusivos.
//No acepta letras, solo numeros.
//Tengo entendido que el usuario solo manejara el proyecto con numeros.
int optionChecker(int lowLimit,int highLimit) {
  int i,option;
  do {
    scanf("%d",&option);
    if ((option < lowLimit) || (option > highLimit))
    {
      printf("Valor esta fuera de rango, Intente de nuevo: ");
    }
  } while ( (option < lowLimit) || (option > highLimit) );
  return option;
}

int fileCheck(FILE * fileToCheck) {
  if (fileToCheck == NULL) {
    printf("Error en apertura del archivo. ");
    return 0;
  }  
  return 1;
}

//------------------------------------------------------------------------------------------
// DATOS DE JUGADOR
//------------------------------------------------------------------------------------------

//Funcion que asigna valores al struct del jugador.
Player assignPlayerData(int choice,int raceCount,FILE *raceFile) {
  int i,carrier;
  Player player;
  char buffer[30];
  rewind(raceFile);
  for(i=5;i<=((raceCount+1)*6);i++) {
    fgets(buffer,sizeof(buffer),raceFile);
    if ((6*choice)==i) {
      break;
    }
  }
  strcpy(player.charName,buffer);
  fgets(buffer,sizeof(buffer),raceFile);
  player.health = retrieveIntfromStr(buffer);
  player.maxHP = player.health;
  fgets(buffer,sizeof(buffer),raceFile);
  player.strength = retrieveIntfromStr(buffer);
  fgets(buffer,sizeof(buffer),raceFile);
  player.iq = retrieveIntfromStr(buffer);
  fgets(buffer,sizeof(buffer),raceFile);
  player.speed = retrieveIntfromStr(buffer);
  fgets(buffer,sizeof(buffer),raceFile);
  player.luck = retrieveIntfromStr(buffer);
  rewind(raceFile);
  return player;
}

void printPlayerData(Player player) {
  printf("\nEstas son las caracteristicas del personaje seleccionado.\n");
  printf("Nombre: %s",player.charName);
  printf("Fuerza: %d\n",player.strength);
  printf("Salud: %d/%d\n",player.health,player.maxHP);
  printf("Inteligencia: %d\n",player.iq);
  printf("Velocidad: %d\n",player.speed);
  printf("Suerte: %d\n",player.luck);
}

int pickPlayer(FILE * raceFile,int * raceCount) {
  int option,confirm,i,j=1;
  char buffer[30];

  //Obtener cant. de razas, despues no me va a hacer falta el valor.
  fgets(buffer,sizeof(buffer),raceFile);
  *raceCount = atoi(buffer);
  rewind(raceFile);
  printf("Existen las siguientes razas...\n");
  for(i=5;i<=( (*raceCount) * 6);i++) {
    fgets(buffer,sizeof(buffer),raceFile);
    if (i%6 == 0) {
      printf("%d. - %s",j,buffer);
      j++;
    }
  }
  //Confirmar que raza usar.
  do {
    printf("\nQue raza deseas escoger? (Rango: %d a %d):",1,*raceCount);
    option = optionChecker(1,*raceCount);
    rewind(raceFile);
    //Leer "option*6" filas, y despues imprimir las 6 restantes.
    for (i=0;i <= ((option)*6); i++) {
      fgets(buffer,sizeof(buffer),raceFile);
      if (i > ((option-1)*6)) {
        printf("%s",buffer);
      }
    }
    printf("\nDeseas confirmar el uso de esa tribu? (1. Si | 0. No):");
    confirm = optionChecker(0,1);
  } while(confirm!=1);
  
  return option;
}

//------------------------------------------------------------------------------------------
// DATOS DEL MAPA
//------------------------------------------------------------------------------------------

//Las siguientes 4 funciones piden un retorno de multiples structs, lo cual no es posible.
//Funcion que retorna un listado de las posiciones de los alienigenas.
Enemy * readMap_Enemy(char arr[MAP_HEIGHT][MAP_WIDTH+3], int * enemyCount){
  int i,j;
  Enemy * enPos = (Enemy*)malloc(sizeof(Enemy)*(*enemyCount));
  for (i = 0 ; i < MAP_HEIGHT ; i++) {
    for (j = 0 ; j < (MAP_WIDTH+3) ; j++){
      if (arr[i][j] == 'A'){
        arr[i][j] = ' ';
        *enemyCount = *enemyCount+1;
        enPos = realloc(enPos,sizeof(Enemy)*(*enemyCount));
        enPos[*enemyCount-1].posX=i;
        enPos[*enemyCount-1].posY=j;
        enPos[*enemyCount-1].hp=50;
      }
    }
  }
  return enPos;
}

//Funcion que retorna un listado de las posiciones de los Items
Item * readMap_Item(char arr[MAP_HEIGHT][MAP_WIDTH+3], int * itemCount){
  int i,j;
  Item * itPos = (Item*)malloc(sizeof(Item)*(*itemCount));
  for (i = 0 ; i < MAP_HEIGHT ; i++) {
    for (j = 0 ; j < (MAP_WIDTH+3) ; j++){
      if (arr[i][j] == '*'){
        arr[i][j] = ' ';
        *itemCount=*itemCount+1;
        itPos = realloc(itPos,sizeof(Item)*(*itemCount));
        itPos[*itemCount-1].posX=i;
        itPos[*itemCount-1].posY=j;
        itPos[*itemCount-1].isTaken=0;
      }
    }
  }
  return itPos;
}

//Funcion que retorna un listado de las posiciones de las Llaves
Item * readMap_Key(char arr[MAP_HEIGHT][MAP_WIDTH+3],int * keyCount){
  int i,j;
  Item * keyPos = (Item*)malloc(sizeof(Item)*(*keyCount));
  for (i = 0 ; i < MAP_HEIGHT ; i++) {
    for (j = 0 ; j < (MAP_WIDTH+3) ; j++){
      if (arr[i][j] == 'L'){
        arr[i][j] = ' ';
        *keyCount=*keyCount+1;
        keyPos = realloc(keyPos,sizeof(Item)*(*keyCount));
        keyPos[*keyCount-1].posX=i;
        keyPos[*keyCount-1].posY=j;
        keyPos[*keyCount-1].isTaken=0;
      }
    }
  }
  return keyPos;
}

//Funcion que cambia la posicion de inicio y final del jugador.
void readMap_PlayerPos(char arr[MAP_HEIGHT][MAP_WIDTH+3],Player * p){
  int i,j;
  for (i = 0 ; i < MAP_HEIGHT ; i++) {
    for (j = 0 ; j < (MAP_WIDTH+3) ; j++){
      if (arr[i][j] == 'E'){
        arr[i][j] = ' ';
        p->posX=i;
        p->posY=j;
      }
      else if (arr[i][j] == 'S'){
        arr[i][j] = ' ';
        p->posXgoal=i;
        p->posYgoal=j;
      }
    }
  }
}

//------------------------------------------------------------------------------------------
// MOSTRAR MAPA
//------------------------------------------------------------------------------------------

//Revisa si es que las coordenadas solicitadas estan en el array.
//Sirve para evitar sobreposiciones
//Retorna 1 si es que el valor esta en el array.
//Retorna 0 si es que el valor no esta en el array.
int checkifCoord(int coordinates[][2],int arrLimit,int coordX,int coordY,int * lastPosition) {
  int i;
  for (i=0;i<arrLimit;i++) {
    if ( (coordinates[i][0] == coordX) && (coordinates[i][1] == coordY) ) {
      *lastPosition = i;
      return 1;
    }
  }
  return 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//Muestra el estado del mapa actual.
void printMap(char arr[MAP_HEIGHT][MAP_WIDTH+3],Enemy * enemyPos,int enemyCount,Item * itPos,int itemCount,Item * keyPos,int keyCount,Player p) {
  int i,j,lastPosition;
  int coordEnemy[enemyCount][2], coordItem[itemCount][2], coordKey[keyCount][2];

  //Agregar las coordenadas de los Enemigos al coordEnemy
  for (i = 0 ; i < enemyCount ; i++){
    coordEnemy[i][0] = enemyPos[i].posX;
    coordEnemy[i][1] = enemyPos[i].posY;
  }

  //Agregar las coordenadas de los Items al coordItem
  for (i = 0 ; i < itemCount ; i++){
    coordItem[i][0] = enemyPos[i].posX;
    coordItem[i][1] = enemyPos[i].posY;
  }

  //Agregar las coordenadas de las Llaves al coordKey
  for (i = 0 ; i < keyCount ; i++){
    coordKey[i][0] = keyPos[i].posX;
    coordKey[i][1] = keyPos[i].posY;
  }

  printf("--------------------------------------------------\n"); //Es mas que nada para evitar al mostrar multiples mapas.

  //Imprimir el mapa alojado en arr.
  for (i = 0 ; i < MAP_HEIGHT ; i++){
    for (j = 0 ; j < (MAP_WIDTH+3) ; j++){
      if (checkifCoord(coordEnemy,enemyCount,i,j,&lastPosition) == 1) {
        if (enemyPos[lastPosition].hp == 0) {printf(" ");}
        else {printf("A");}
      }
      else if (checkifCoord(coordItem,itemCount,i,j,&lastPosition) == 1) {
        if (itPos[lastPosition].isTaken == 1) {printf(" ");}
        else {printf("*");}
      }
      else if (checkifCoord(coordKey,keyCount,i,j,&lastPosition) == 1) {
        if (keyPos[lastPosition].isTaken == 1) {printf(" ");}
        else {printf("L");}
        }
      else if ((p.posX == i) && (p.posY == j)) { printf("J"); }
      else { printf("%c",arr[i][j]); }
    }
  }

  printf("\n");
}

//------------------------------------------------------------------------------------------
// MOVIMIENTO DEL JUGADOR
//------------------------------------------------------------------------------------------

//Funcion que revisa si el movimiento que el jugador intenta hacer es posible.
//Lo que hace es revisar si ya hay algo ahi, para evitar sobreposiciones.
//Retorna 0 si el movimiento esta bloqueado.
//Retorna 1 si el movimiento esta libre.
//Retorna 2 si el movimiento esta libre y hay un item
//Retorna 3 si el movimiento esta libre y hay una llave.
int checkifMovePlayer(char arr[MAP_HEIGHT][MAP_WIDTH+3],Enemy * enemyPos,int enemyCount,Item * itPos,int itemCount,Item * keyPos,int keyCount,Player p,int movement, int * keyLeftOnMap){
  int i,j,tempX = p.posX,tempY = p.posY, lastPos;
  int coordEnemy[enemyCount][2], coordItem[itemCount][2], coordKey[keyCount][2];

  //Agregar las coordenadas de los Enemigos al coordEnemy
  for (i = 0 ; i < enemyCount ; i++){
    coordEnemy[i][0] = enemyPos[i].posX;
    coordEnemy[i][1] = enemyPos[i].posY;
  }

  //Agregar las coordenadas de los Items al coordItem
  for (i = 0 ; i < itemCount ; i++){
    coordItem[i][0] = enemyPos[i].posX;
    coordItem[i][1] = enemyPos[i].posY;
  }

  //Agregar las coordenadas de las Llaves al coordKey
  for (i = 0 ; i < keyCount ; i++){
    coordKey[i][0] = keyPos[i].posX;
    coordKey[i][1] = keyPos[i].posY;
  }

  //Obtener posicion futura.
  switch(movement){
    case 1: //Intenta moverse hacia arriba
      tempY++;
      break;
    case 2: //Intenta moverse hacia la derecha
      tempX++;
      break;
    case 3: //Intenta moverse hacia abajo
      tempY--;
      break;
    case 4: //Intenta moverse hacia la izquierda
      tempX--;
    break;
  }

  //-----Revisar si el lugar a moverse esta bloqueado.-----
  if ( checkifCoord(coordEnemy,enemyCount,tempX,tempY,&lastPos) == 1) { //Hay un enemigo en el camino
    if (enemyPos[lastPos].hp == 0) {return 1;} //El enemigo esta muerto
    else {return 0;} //El enemigo esta vivo
  }

  else if (arr[tempX][tempY] == ' ') {return 1;} //No hay nada
  
  else if ( (checkifCoord(coordItem,itemCount,tempX,tempY,&lastPos) == 1) ) { //Hay un Item
    if (itPos[lastPos].isTaken == 1) {return 1;} //El item fue tomado.
    else {itPos[lastPos].isTaken = 1; return 2;} //El item aun esta, y sera tomado ahora.
  }
  
  else if ( (checkifCoord(coordKey,keyCount,tempX,tempY,&lastPos) == 1) ) { //Hay una Llave
    if (keyPos[lastPos].isTaken == 1) {return 1;} //La llave ya habia sido tomada.
    else {keyPos[lastPos].isTaken = 1; *keyLeftOnMap = *keyLeftOnMap - 1; return 3;} //La llave aun esta, y sera tomada
  }
  
  else {return 0;} //Hay cualquier cosa no definida, como las paredes
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//Funcion que mueve al jugador de forma directa.
void movePlayer(Player * p,int direction){
  switch(direction){
    case 1: //Intenta moverse hacia arriba
      p->posY = p->posY + 1;
      break;
    case 2: //Intenta moverse hacia la derecha
      p->posX = p->posX + 1;
      break;
    case 3: //Intenta moverse hacia abajo
      p->posY = p->posY - 1;
      break;
    case 4: //Intenta moverse hacia la izquierda
      p->posX = p->posX - 1;
    break;
  }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//Lo mismo que el anterior, pero inversa.
void undoMovePlayer(Player *p,int direction){
  switch(direction){
    case 1: //Intenta moverse hacia arriba
      p->posY = p->posY - 1;
      break;
    case 2: //Intenta moverse hacia la derecha
      p->posX = p->posX - 1;
      break;
    case 3: //Intenta moverse hacia abajo
      p->posY = p->posY + 1;
      break;
    case 4: //Intenta moverse hacia la izquierda
      p->posX = p->posX + 1;
    break;
  }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//Funcion que revisa si se llego a la meta del mapa con todas las llaves
//Retorna 1 si se llego a la meta
//Retorna 0 si no se llego a la meta
int checkGoalReachKeys(Player p,int keyLeft){
  if ( ((p.posY == p.posYgoal) && (p.posX == p.posXgoal)) && keyLeft == 0 ) {return 1;}
  else {return 0;}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//Simplemente le pide al jugador que va a hacer en ese instante.
int actionRequest(FILE * log){
  int option;
  printf("Que desea hacer?:\n");
  printf("1. Moverse hacia la Derecha.\n");
  printf("2. Moverse hacia Abajo.\n");
  printf("3. Moverse hacia la Izquierda.\n");
  printf("4. Moverse hacia Arriba.\n");
  printf("5. Usar un Item. (No Implementado)\n");
  printf("6. Cambiar de arma. (No Implementado)\n");
  printf("7. Atacar. (No Implementado)\n");
  printf("Haga su seleccion:");
  option = optionChecker(1,7);

  switch(option){
    case 1:
      fprintf(log,"El jugador se movio hacia la Derecha\n");
      break;
    case 2:
      fprintf(log,"El jugador se movio hacia Abajo\n");
      break;
    case 3:
      fprintf(log,"El jugador se movio hacia la Izquierda\n");
      break;
    case 4:
      fprintf(log,"El jugador se movio hacia Arriba\n");
      break;
    case 5:
      fprintf(log,"El jugador ha usado un item.\n");
      break;
    case 6:
      fprintf(log,"El jugador ha cambiado de arma.\n");
      break;
    case 7:
      fprintf(log,"El jugador ha intentado atacar.\n");
      break;
  }

  return option;
}

//------------------------------------------------------------------------------------------
// MOVIMIENTO DE LOS ALIENS
//------------------------------------------------------------------------------------------

//Funcion que mueve los aliens al jugador mas rapido.
void moveEnemyToPlayer(char map[MAP_HEIGHT][MAP_WIDTH+3],Enemy * enemyPos,int enemyCount,Item * itemPos,int itemCount,Item * keyPos,int keyCount,Player p){
  int i;

  //Revisar donde esta el jugador respecto al alien.
  for (i=0;i<enemyCount;i++){
    if (enemyPos[i].hp == 0) {continue;} //Me salto la iteracion, no me sirven los aliens muertos
    else{
      //Hay que crear una forma de mover a los alienes en el plano, pero no tengo idea de como..



      //
    }
  }
}

//------------------------------------------------------------------------------------------
// CARGA DE MAPA
//------------------------------------------------------------------------------------------

//Ya que tengo que usar esta funcion 3 veces, en vez de copypaste, voy a ser eficiente.
void mapRun(FILE* mapFile,FILE* log,Player base){
  int i,enemyCount=0,itemCount=0,keyCount=0,keyLeft=0,actionChoice;
  char map[MAP_HEIGHT][MAP_WIDTH+3];
  Player p = base; //Es para poder alterar los valores del jugador sin problemas...

  //Cargar el mapa en el char map.
  for (i=0;i<MAP_HEIGHT;i++) {fgets(map[i],(MAP_WIDTH+3),mapFile);} fclose(mapFile);

  Enemy * enemyPosition = readMap_Enemy(map,&enemyCount);
  Item * itemPosition = readMap_Item(map,&itemCount);
  Item * keyPosition = readMap_Key(map,&keyCount);
  keyLeft = keyCount;
  readMap_PlayerPos(map,&p);

  do{
    printMap(map,enemyPosition,enemyCount,itemPosition,itemCount,keyPosition,keyCount,p);
    actionChoice = actionRequest(log);
    printf("\n\n");
    //Movimiento
    if (actionChoice <=4){
      switch( checkifMovePlayer(map,enemyPosition,enemyCount,itemPosition,itemCount,keyPosition,keyCount,p,actionChoice,&keyLeft) ){
        case 0: //Algo esta en el camino.
          printf("El camino esta bloqueado.\n");
          break;
        case 1: //Libre
          movePlayer(&p,actionChoice);
          if ( ((p.posX == p.posXgoal) && (p.posY == p.posYgoal)) && keyLeft !=0){
            printf("El jugador no ha obtenido todas las llaves aun.\n");
            undoMovePlayer(&p,actionChoice);
          }
          break;
        case 2: //Item (FUncion que anula los items ya obtenidos esta en checkifMovePlayer)
          movePlayer(&p,actionChoice);
          break;
        case 3: //Llave (Funcion que anula los items ya obtenidos esta en checkifMovePlayer)
          movePlayer(&p,actionChoice);
          break;
      }
    }
  }while (checkGoalReachKeys(p,keyLeft) == 0);
  //Se llego al final del mapa

  free(enemyPosition);
  free(itemPosition);
  free(keyPosition);
}

//------------------------------------------------------------------------------------------
// MAIN
//------------------------------------------------------------------------------------------

int main() {
  //Creando variables que me van a servir
  int i,playerChoice,raceCount=0,enemyCount,itemCount,keyCount,keyLeft,actionChoice;
  FILE *tribus, *mapFile, *log;
  Player p;

  //Creando el archivo de logs
  time_t rawTime;
  struct tm *infoDataThing;
  time(&rawTime);
  infoDataThing = localtime(&rawTime);
  char logFilename[80];
  char fileFormat[] = ".log";
  strftime(logFilename,80,"%Y%m%d_%H%M",infoDataThing);
  log = fopen(strcat(logFilename,fileFormat),"a");

  //Llamando el archivo
  tribus=fopen("tribus.in","r");
  //Verificando que el archivo Tribus.in exista
  if (fileCheck(tribus) == 0) { printf("(tribus.in)\n");exit(0); }
  //Solicitar al usuario que personaje usar, y asignarlo.
  playerChoice=pickPlayer(tribus,&raceCount);
  p=assignPlayerData(playerChoice,raceCount,tribus);
  fclose(tribus);

  enemyCount=0;itemCount=0;keyCount=0;keyLeft=0;

  //----------------------------------------------------------------------------------------------------
  //MAPA 1
  if (fileCheck(mapFile) == 0) { printf("(Laberinto_00.in)\n");exit(0); }
  mapFile=fopen("Laberinto_00.in","r");
  mapRun(mapFile,log,p);

  //----------------------------------------------------------------------------------------------------
  //MAPA 2
  if (fileCheck(mapFile) == 0) { printf("(Laberinto_01.in)\n");exit(0); }
  mapFile=fopen("Laberinto_01.in","r");
  mapRun(mapFile,log,p);

  //----------------------------------------------------------------------------------------------------
  //MAPA 1
  if (fileCheck(mapFile) == 0) { printf("(Laberinto_02.in)\n");exit(0); }
  mapFile=fopen("Laberinto_02.in","r");
  mapRun(mapFile,log,p);

  //Cerrar el archivo log
  fclose(log);
  return 0;
}