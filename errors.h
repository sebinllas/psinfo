/*Códigos de error para las eventualidades de:
*BAD_ARGUMENT para formato invalido de algún PID 
*PROC_NOT_FOUND para procesos que no están en ejecución
*BAD_FLAG para parametros diferentes de -l y -r
*/
enum ERROR_CODES
{
  BAD_ARGUMENT = 400,
  PROC_NOT_FOUND = 404,
  BAD_FLAG = 401,
};