#ifndef CS240_H
#define CS240_H

#ifndef TEST_FILE
#define TEST_FILE(f,s,s1) 	\
		if (NULL==f){		\
			fprintf(stderr, "%s: can't open %s\n", s,s1);\
			exit(1);}
#endif


#ifndef TEST_POINTER
#define TEST_POINTER(p, s) \
		if (NULL==p){		\
			fprintf(stderr, "Pointer %s is NULL", s);\
			exit(1);}			
#endif




#endif