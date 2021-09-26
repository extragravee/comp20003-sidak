/* sample file
	hello darkness my old friend\n
	sad violing music\n
	covid19 \n
	\EOF\

	*/
	char buffer[1000];
	char character;
	char* sentences[10];

	[char *] -> [hello darkness my old friend\0]
	[char *] -> [tymara is a c guru good\0]
	[char *] ->
	[char *] ->
	[char *] ->
	[char *] ->

	buffer = [tymara is a c guru good\0]

	int counter = 0;
	int sentence_counter = 0;
	while(scanf("%c", &character)==1){
		if(character==EOF){
			break;
		} else if (character=='\n'){
			buffer[counter] = '\0';
			char *temp = (char *) malloc(sizeof(char)*strlen(buffer)+1);
			strcpy(temp, buffer);
			sentences[sentence_counter++] = temp;

			counter = 0;
		}
		else {
			buffer[counter++] = character;
		}

	}
