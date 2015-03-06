int ft_print(char *texte, ...)
{
	int tailleChaine = 0, i;
	char chaineUtilisable[16] = {0}; //chaîne intermédiaire pour écrire dans le fichier
	va_list ap;
	va_start(ap, texte);
	
	// calcul de la taille de la chaîne à écrire dans un fichier
	tailleChaine = strlen(texte);
	
	// parcours de chaque caractère
	for(i = 0; i < tailleChaine; i++)
	{
		if(texte[i] == '%')
		{
			i++; // on se place au caractère suivant pour savoir ce que c'est
			switch(texte[i]){
			case 'a' :
				sprintf(chaineUtilisable, "%ld", va_arg(ap, int));
				fputs(chaineUtilisable, fichier);
				break;
			case 'b' :
				sprintf(chaineUtilisable, "%ld", va_arg(ap, long));
				fputs(chaineUtilisable, fichier);
				break;
			case 'c' :
				sprintf(chaineUtilisable, "%lf", va_arg(ap, float));
				fputs(chaineUtilisable, fichier);
				break;
			case 'd' :
				sprintf(chaineUtilisable, "%lf", va_arg(ap, double));
				fputs(chaineUtilisable, fichier);
				break;
			case 'e' :
				fputs(va_arg(ap, char*), fichier);
				break;
			case '%' :
				fputc('%', fichier);
				break;
			}
		}
		else
		{
			fputc(texte[i], fichier);
		}
	}
	va_end(ap);
}
