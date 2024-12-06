#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "PQ.h"

// TODO: Aqui você deve implementar uma fila com prioridade mínima para
//       ordenar os eventos por tempo, isto é, o evento com o menor tempo tem
//       a maior prioridade. Veja as funções definidas em 'event.h' para
//       a manipulação das estruturas de evento. A princípio, as funções já
//       existentes em 'event.h' são suficientes para implementar a simulação,
//       isto é, você não precisa implementar mais nada lá.
//
//       Você é livre para implementar a fila com prioridade da forma que quiser
//       mas é recomendado usar um min-heap para obter um bom desempenho. As
//       simulações maiores geram uma quantidade grande de eventos: um
//       limite superior frouxo (mas seguro) para o número máximo simultâneo de
//       eventos é N^3, aonde N é o número de partículas.

// TODO: Crie a struct pq.
struct pq {
    int maxSz, currSz;
    Event** events;   
};

/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ* PQ_create(int max_N) {
    // TODO: Implemente a criação da fila que suporta no máximo o número de
    //       de eventos informados no parâmetro.
    if(max_N <= 0) return NULL;

    PQ* p = malloc(sizeof(PQ));
    p->currSz = 0;
    p->maxSz = max_N;
    p->events = calloc(max_N, sizeof(Event*));
    return p;
}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq) {
    // TODO: Implemente essa função que libera toda a memória da fila,
    //       destruindo inclusive os eventos que estavam na fila.
    if(pq == NULL) return;

    int currSz = PQ_size(pq);
    for(int i = 0; i < currSz; i++) {
        destroy_event(pq->events[i]);
    }
    free(pq->events);
    free(pq);
}

static int idxParent(int id) {
    return (int)( (id-1)/2 );
}

static int idxLeftSon(int id) {
    return 2*id + 1;
}

static int idxRightSon(int id) {
    return 2*id + 2;
}

/*
 * Insere o evento na fila segundo o seu tempo.
 */
void PQ_insert(PQ *pq, Event *e) {
    // TODO: Implemente essa função que insere o evento dado na fila segundo
    //       o tempo do evento.
    //       Assuma que 'e' não é nulo. É importante testar overflow (inserção
    //       em uma fila que já contém o número máximo de eventos) para evitar
    //       dores de cabeça com acessos inválidos na memória.
    if(pq->currSz == pq->maxSz) {
        printf("PQ is full.\n");
        return;
    }

    
    pq->events[pq->currSz] = e;
    pq->currSz += 1;

    int id = pq->currSz;
    int pid = idxParent(id);
    while ( compare(pq->events[id], pq->events[pid]) < 0 ) { // enquanto filho menor que o pai
        Event* temp = pq->events[id];
        pq->events[id] = pq->events[pid];
        pq->events[pid] = temp;
        id = pid;
        int id = pq->currSz;
        int pid = idxParent(id);
    }
    
}

/*
 * Remove e retorna o evento mais próximo.
 */
Event* PQ_delmin(PQ *pq) {
    // TODO: Implemente essa função que remove o evento com o menor tempo da
    //       fila e o retorna.
    if(PQ_is_empty(pq)) {
        printf("PQ is empty.\n");
        return NULL;
    }

    Event* min = pq->events[0];
    pq->currSz -= 1;

    int id = 0;
    while(id != pq->currSz) { // enquanto o evento retirado não estiver no final (posição livre)
        int lft_son = idxLeftSon(id);
        int rgt_son = idxRightSon(id);
        Event* temp = pq->events[id];

        if(compare(pq->events[lft_son], pq->events[rgt_son]) < 0) {
            pq->events[id] = pq->events[lft_son];
            pq->events[lft_son] = temp;
            id = lft_son;
        } else {
            pq->events[id] = pq->events[rgt_son];
            pq->events[rgt_son] = temp;
            id = rgt_son;
        }


    }
}

/*
 * Testa se a fila está vazia.
 */
bool PQ_is_empty(PQ *pq) {
    // TODO: Implemente essa função.
    return (pq->currSz == 0);
}

/*
 * Retorna o tamanho da fila.
 */
int PQ_size(PQ *pq) {
    // TODO: Implemente essa função.
    return pq->currSz;
}
