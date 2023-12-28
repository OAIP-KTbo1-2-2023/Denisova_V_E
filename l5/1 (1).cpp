#pragma warning(disable : 4996)
#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#define MAX_INFO_SIZE 20 // Макс размер строки данных в структуре
#define MAX_LIST_GOS_SIZE 20 // Макс размер списка 

struct gosudarstvo {
 char country[MAX_INFO_SIZE];
 char capital[MAX_INFO_SIZE];
 char language[MAX_INFO_SIZE];
 char population[MAX_INFO_SIZE];
 char area[MAX_INFO_SIZE];
 char valmoney[MAX_INFO_SIZE];
 char gosstroy[MAX_INFO_SIZE];
 char perw[MAX_INFO_SIZE];
 char perm[MAX_INFO_SIZE];

};

int menu_func() {
 int choise;
 puts("\nМеню функций: ");
 puts("1. Запись государства \n2. Поиск \n3. Сортировка \n4. Вывод имеющихся данных \n5. Кол-во записей \n6. Чистка \n7. Сохранение");
 puts("Введите номер функции: ");
 scanf("%i", &choise);
 return choise;
}


int record_struct(gosudarstvo* gosudarstvo, unsigned id) {
 FILE* input = fopen("C:/Users/nikak/AIP_labs/l5/data.txt", "a");
 int new_count;

 puts("Кол-во новых государств для записи: ");
 scanf("%i", &new_count);

 if (input == NULL) perror("Ошибка открытия файла data.txt для записи и хранения данных о государствах");
 else {
  for (int i = 0; i < new_count; i++) {
   puts("Ввод нового государства: ");

   puts("Страна: ");
   scanf("%s", &gosudarstvo[id + i].country);
   puts("Столица: ");
   scanf("%s", &gosudarstvo[id + i].capital);
   puts("Язык: ");
   scanf("%s", &gosudarstvo[id + i].language);
   puts("Население: ");
   scanf("%s", &gosudarstvo[id + i].population);
   puts("Площадь территории: ");
   scanf("%s", &gosudarstvo[id + i].area);
   puts("Валюта: ");
   scanf("%s", &gosudarstvo[id + i].valmoney);
   puts("Государственный строй: ");
   scanf("%s", &gosudarstvo[id + i].gosstroy);
   puts("Процент женщин: ");
   scanf("%s", &gosudarstvo[id + i].perw);
   puts("Процент мужчин: ");
   scanf("%s", &gosudarstvo[id + i].perm);

   fprintf(input, "%s %s %s %s %s %s %s %s %s \n",
    gosudarstvo[id + i].country, gosudarstvo[id + i].capital, gosudarstvo[id + i].language, gosudarstvo[id + i].population, gosudarstvo[id + i].area,
    gosudarstvo[id + i].valmoney, gosudarstvo[id + i].gosstroy, gosudarstvo[id + i].perw, gosudarstvo[id + i].perm);
  }
 }

 fclose(input);
 return id;
}


int read_data(gosudarstvo* gos) {
 FILE* output = fopen("C:/Users/nikak/AIP_labs/l5/data.txt", "r");
 unsigned count = 0;
 if (output == NULL) perror("Ошибка открытия файла data.txt для записи информации о государствах в структуры");
 else {

  char stroke[256];
  int i = 0;

  while (fgets(stroke, sizeof(stroke), output) != NULL) {
   sscanf(stroke, "%s %s %s %s %s %s %s %s %s \n", &gos[i].country, &gos[i].capital, &gos[i].language, &gos[i].population, &gos[i].area, &gos[i].valmoney, &gos[i].gosstroy, &gos[i].perw, &gos[i].perm);
   count++;
   i++;
  }

 }
 if (count == 0) puts("Сейчас данных о государствах нет\n");

 fclose(output);
 return count;
}

// Функция вывода структур в консоль. Работает, проверено на практике - есть вывод
void print(gosudarstvo* gos, int count) {

 if (gos == NULL) printf("Нет государств");
 else {
  puts("\n Данные о государствах: \n");
  for (int i = 0; i < count; i++) {
   printf("%s \t %s \t %s \t %s \t %s \t %s \t %s \t %s \t %s \n", &gos[i].country, &gos[i].capital, &gos[i].language, &gos[i].population, &gos[i].area, &gos[i].valmoney, &gos[i].gosstroy, &gos[i].perw, &gos[i].perm);
  }
 }

}

// Функция вывода структур в файл. Работает, проверено путем записи в файл
void output_file(gosudarstvo* gosudarstvo, unsigned count) {
 FILE* file = fopen("C:/Users/nikak/AIP_labs/l5/output.txt", "w");

 if (file == NULL) perror("Ошибка открытия файла");
 else {

  if (gosudarstvo == NULL) fprintf(file, "Нет покупателей");
  else {
   for (int i = 0; i < count; i++) {
    fprintf(file, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s \n", gosudarstvo[i].country, gosudarstvo[i].capital, gosudarstvo[i].language, gosudarstvo[i].population, gosudarstvo[i].area,gosudarstvo[i].valmoney, gosudarstvo[i].gosstroy, gosudarstvo[i].perw, gosudarstvo[i].perm);
   }

   puts("Вывод завершен.\n");
}
 }

 fclose(file);
}

unsigned int menu_param() {
 unsigned int choise;
 puts("Список параметров: ");
 puts("1.Страна \n2.Столица \n3.Язык \n4.Население \n5.Площадь территории \n6.Денежная единица \n7.Государственный строй \n8.Процент женщин \n9.Процент мужчин");
 puts("Введите номер нужного параметра: ");
 do {
  scanf("%u", &choise);
  printf("Выбрано: %u\n", choise);
 } while (choise < 1 || choise > 9);
 return choise;
}

void search(gosudarstvo* gosudarstvo, int count) {
 char s_goal[MAX_INFO_SIZE];
 unsigned int int_goal = 0, param, res;

 puts("Введите параметр для поиска: ");
 param = menu_param();
 puts("Введите значение параметра для поиска: ");

 if (param >= 6)
  scanf("%s", &int_goal);
 else scanf("%s", &s_goal);


 for (int i = 0; i <= count; i++) {
  res = 0;
  switch (param) {
  case 1: if (strcmp(gosudarstvo[i].country, s_goal) == 0) res = 1;
   break;
  case 2: if (strcmp(gosudarstvo[i].capital, s_goal) == 0) res = 1;
   break;
  case 3:  if (strcmp(gosudarstvo[i].language, s_goal) == 0) res = 1;
   break;
  case 4: if (strcmp(gosudarstvo[i].population,s_goal) == 0) res = 1;
   break;
  case 5: if (strcmp(gosudarstvo[i].area, s_goal) ==0) res = 1;
   break;
  case 6: if (strcmp(gosudarstvo[i].valmoney, s_goal) == 0) res = 1;
   break;
  case 7: if (strcmp(gosudarstvo[i].gosstroy, s_goal) == 0) res = 1;
   break;
  case 8: if (strcmp(gosudarstvo[i].perw, s_goal) == 0) res = 1;
   break;
  case 9:if (strcmp(gosudarstvo[i].perm, s_goal) == 0) res = 1;
   break;
  default: break;
  }
  if (res == 1) printf("Найдено: %s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s \n",
   gosudarstvo[i].country, gosudarstvo[i].capital, gosudarstvo[i].language, gosudarstvo[i].population, gosudarstvo[i].area,
   gosudarstvo[i].valmoney, gosudarstvo[i].gosstroy, gosudarstvo[i].perw, gosudarstvo[i].perm);
 }
 if (res == 0)
  puts("Совпадений не найдено");
}

// Функции для указания в qsort, отдельно по параметрам для возможности выбора
int country_cmp(const void* a, const void* b) {
 return strcmp(((gosudarstvo*)a)->country, ((gosudarstvo*)b)->country);
}

int capital_cmp(const void* a, const void* b) {
 return strcmp(((gosudarstvo*)a)->capital, ((gosudarstvo*)b)->capital);
}

int language_cmp(const void* a, const void* b) {
 return strcmp(((gosudarstvo*)a)->language, ((gosudarstvo*)b)->language);
}

int population_cmp(const void* a, const void* b) {
 return ((gosudarstvo*)a)->population - ((gosudarstvo*)b)->population;
}

int area_cmp(const void* a, const void* b) {
 return ((gosudarstvo*)a)->area - ((gosudarstvo*)b)->area;
}

int valmoney_cmp(const void* a, const void* b) {
 return strcmp(((gosudarstvo*)a)->valmoney, ((gosudarstvo*)b)->valmoney);
}

int gosstroy_cmp(const void* a, const void* b) {
 return strcmp(((gosudarstvo*)a)->gosstroy, ((gosudarstvo*)b)->gosstroy);
}

int perw_cmp(const void* a, const void* b) {
 return ((gosudarstvo*)a)->perw - ((gosudarstvo*)b)->perw;
}

int perm_cmp(const void* a, const void* b) {
 return ((gosudarstvo*)a)->perm - ((gosudarstvo*)b)->perm;
}
void sorting(gosudarstvo* gos, int count) {

 puts("Введите значение параметра для сортировки: ");

 switch (menu_param()) {
 case 1: qsort(gos, count, sizeof(gosudarstvo), country_cmp);
  break;
 case 2: qsort(gos, count, sizeof(gosudarstvo), capital_cmp);
  break;
 case 3: qsort(gos, count, sizeof(gosudarstvo), language_cmp);
  break;
 case 4: qsort(gos, count, sizeof(gosudarstvo), population_cmp);
  break;
 case 5: qsort(gos, count, sizeof(gosudarstvo), area_cmp);
  break;
 case 6: qsort(gos, count, sizeof(gosudarstvo), valmoney_cmp);
  break;
 case 7: qsort(gos, count, sizeof(gosudarstvo), gosstroy_cmp);
  break;
 case 8: qsort(gos, count, sizeof(gosudarstvo), perw_cmp);
  break;
 case 9: qsort(gos, count, sizeof(gosudarstvo), perm_cmp);
  break;
 default: break;
 }


 puts("Отсортировано");
 print(gos, count);
 puts("Обновление файла вывода");
 output_file(gos, count);
}

// Функция очищения файлов
void clear_files() {
 FILE* data = fopen("C:/Users/nikak/AIP_labs/l5/data.txt", "w");
 FILE* output = fopen("C:/Users/nikak/AIP_labs/l5/output.txt", "w");
 fclose(data);
 fclose(output);
}

int main()
{
 setlocale(LC_ALL, "Russian");
 gosudarstvo* list_goses = (gosudarstvo*)malloc(sizeof(gosudarstvo) * MAX_LIST_GOS_SIZE);
 gosudarstvo* gosudarstvo = { 0 };
 unsigned count = read_data(list_goses);

 printf("На данный момент записей о государствах: %u", count);

 // Меню функций
 switch (menu_func()) {
 case 1: count = record_struct(list_goses, count);
  break;
 case 2:search(list_goses, count);
  break;
 case 3:sorting(list_goses, count);
  break;
 case 4:print(list_goses, count);
  break;
 case 5:output_file(list_goses, count);
  break;
 case 6: clear_files();
  break;
 case 7:
  free(list_goses);
  return 0;
 default: menu_func();
 }

 main();
}