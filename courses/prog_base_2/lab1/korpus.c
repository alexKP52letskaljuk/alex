#include "aud.h"
#include "korpus.h"

struct korpus_s {
    aud_t ** clases;
    int audCount;
    char * name;
};

struct aud_s {
    int numb;
    clock_t time;
    int seats;
};

static aud_t * aud_new(int seats, int numb)
{
    aud_t * self = NULL;
    self = malloc(sizeof(struct aud_s));
    if (NULL == self)
        return NULL;
    self->seats = seats;
    self->time = clock();
    self->numb = numb;
    return self;
}


korpus_t * korpus_new(char * name, int clases, int seats[clases])
{
    int i, j;
    korpus_t * self = NULL;
    self = malloc(sizeof(struct korpus_s));
    if(self == NULL || clases <= 0)
        return NULL;
    self->name = malloc(sizeof(char) * strlen(name));
    self->audCount = clases;
    if (self->name == NULL)
    {
        free(self);
        return NULL;
    }
    strcpy(self->name, name);
    self->clases = malloc(sizeof(aud_t *) * clases);
    for (i = 0; i < clases; i++){
        self->clases[i] = aud_new(seats[i], i);
        if (self->clases[i] == NULL)
        {
            for(j = 0; j < i; j++)
                aud_free(self->clases[j]);
            free(self->name);
            free(self);
            return NULL;
        }
    }
    return self;
}

enum boolean_e korpus_aud_take(korpus_t * self, int numb, int time)
{
    if (numb < 0 || numb >= self->audCount)
        return FALSE;
    return aud_take(self->clases[numb], time);
}

enum boolean_e korpus_aud_isBusy(korpus_t * self, int numb)
{
    if (numb < 0 || numb >= self->audCount)
        return FALSE;
    return aud_isBusy(self->clases[numb]);
}

int korpus_audsCount(korpus_t * self)
{
    return self->audCount;
}

int korpus_aud_numberOfSeats(korpus_t * self, int numb)
{
    if (numb < self->audCount && numb >= 0)
        return aud_numberOfSeats(self->clases[numb]);
    return -1;
}

void korpus_free(korpus_t * self)
{
    int j;
    for(j = 0; j < self->audCount; j++)
        aud_free(self->clases[j]);
    free(self->name);
    free(self);
}

void aud_free(aud_t * self)
{
    free(self);
}

aud_t * korpus_get_aud(korpus_t * self, int numb)
{
    if (numb < self->audCount && numb >= 0)
        return self->clases[numb];
    return NULL;
}
