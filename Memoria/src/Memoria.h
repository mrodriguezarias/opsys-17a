/*
 * Memoria.h
 *
 *  Created on: 3/4/2017
 *      Author: utnso
 */

#ifndef MEMORIA_H_
#define MEMORIA_H_

#include "protocol.h"
#include <signal.h>

typedef struct{
	char* puerto;
	int marcos;
	int marco_size;
	int entradas_cache;
	int cache_x_proc;
	char* reemplazo_cache;
	int retardo_memoria;
}t_memoria;

void inicializar(t_memoria* config);

void *atenderSenial(int sig, siginfo_t *info, void *ucontext);

void *crearServidor(t_memoria* config);

void *procesarCliente(socket_t *sockfd);

int validarHandshake(socket_t sockfd, header_t *header);

void procesarMensaje(socket_t sockfd);

void interpreteDeComandos(t_memoria* config);

#endif /* MEMORIA_H_ */
