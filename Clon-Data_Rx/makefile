################################################################
# Author: Leandro Schiavoni
# Organizar archivos fuente en .inc (.h) y .src (.c)
# Forma de uso: pararse en la terminal en el mismo nivel del
# makefile, hacer "make <algo>", por ejemplo, "make callex"
################################################################

TARGET	= ${BIN_DIR}/${notdir ${shell pwd}}
SRC_DIR	= src
INC_DIR  = inc
OBJ_DIR	= out
BIN_DIR  = bin
BUP_DIR  = backup
SRCS	   = ${wildcard ${SRC_DIR}/*.c}
OBJS	   = ${subst ${SRC_DIR},${OBJ_DIR},${SRCS:.c=.o}}
CFLAGS	= -Wall -Wextra -I${INC_DIR}

# Buscar y analizar si es necesario ignorar archivos
# Que pasa si el target depende de solo algunos archivos y no de todos los .c?
# Tiene algún sentido eso?? Se autoanalizará??

print:
# Solo para debug
	@echo ${SRCS}
	@echo ${OBJS}

# TODO Agregar una receta que ordene archivos sueltos
# sort:


all: ${TARGET}
# Compila, linkea y genera ejecutable

call: clean all
# Primero hace un clean y luego llama a all

callex: call ex
# call seguido de ejecucion

.PHONY: backup
backup:
# genera backup de estado actual, ojo, pisa anterior backup
# Falta un tag con la fecha para evitar esto
	@mkdir -p ${BUP_DIR}
	cp -rf ${SRC_DIR} ${INC_DIR} makefile ${BUP_DIR}

${TARGET}: ${OBJS}
	@mkdir -p ${BIN_DIR}
	gcc ${CFLAGS} ${OBJS} -o ${TARGET}

${OBJ_DIR}/%.o : ${SRC_DIR}/%.c
	@mkdir -p ${OBJ_DIR}
	gcc -c -MD ${CFLAGS} $< -o $@

-include ${OBJ_DIR}/*.d

clean:
# Elimina todos los archivos intermedios y el ejecutable
	rm -rf ${BIN_DIR} ${OBJ_DIR}

# Ejecuta el binario resultante
ex:
	./${TARGET}