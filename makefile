compilador = cc #escolha do compilador
Objetivo = main-PL403.exe #objetivo principal
.PHONY: all clean #nao vão fazer nada

all : $(Objetivo)

$(Objetivo) : functions-PL403.o main-PL403.o
	$(compilador) -o $@ $^ -lm
%.o : %.c
	$(compilador) -c $<
clean:
	rm *.o 
	@echo "Programa: removendo todos os ficheiros!"







