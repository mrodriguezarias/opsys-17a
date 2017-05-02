#ifndef thread_h
#define thread_h

#include <pthread.h>
#include <signal.h>

typedef pthread_t thread_t;

/**
 * Crea un hilo de usuario usando la librería de hilos POSIX.
 * @param routine Rutina que ejecutará el hilo.
 * @param arg (Opcional) Argumento pasado a la rutina.
 * @return Identificador del hilo creado.
 */
thread_t _thread_create(void *(*routine)(void *), void *arg);
#define thread_create(...) __thread_create(__VA_ARGS__, 0, 0)
#define __thread_create(r, a, ...) _thread_create((void *(*)(void *))(r), (void *)(a))

/**
 * Establece la rutina que se ejecutará al recibir determinada señal.
 * @param signal Descriptor de la señal.
 * @param routine (Opcional) Rutina que se ejecutará.
 */
void _thread_signal_set(int signal, void (*routine)(int));
#define thread_signal_set(...) __thread_signal_set(__VA_ARGS__, 0, 0)
#define __thread_signal_set(s, r, ...) _thread_signal_set(s, (void (*)(int))(r))

/**
 * Manda una señal al hilo para cancelarlo y espera a que el hilo termine.
 * @param thread Hilo que se va a cancelar.
 */
void thread_kill(thread_t thread);

#endif /* thread_h */
