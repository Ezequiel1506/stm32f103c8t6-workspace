/* WRITE */

fresult = f_open (&fil, "file2.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE);
/*Writing text*/
strcpy(buffer, "Aca va ña info\n");
fresult= f_write(&fil, buffer, bufsize(buffer), &bw);

/*Close file*/
f_close(&fil);
bufclear();

/* UPDATE */

/*open the file*/
fresult = f_open (&fil, "file2.txt", FA_OPEN_ALWAYS  | FA_WRITE);

/*move till last line*/
fresult = f_lseek(&fil, fil.fsize);

/*write*/
f_result=f_puts("this is the update", &fill);

f_close(&fil) 


/*PUTS and GET*/

fresult = f_open(&fil, "file.txt", FA_OPEN_ALWAYS | FA_READ|FA_WRITE);

fresult= f_puts("Data", &fil);

fresult=f_close(&fil)


fresult = f_open(&fil, "file.txt",FA_READ);

f_gets(buffer, fil.fsize,&fil)

f_close(&fil)


