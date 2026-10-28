#pragma once
#ifndef DEALER_H
#define DEALER_H
#include "Participante.h"


    class Dealer : public Participante {
    public:
        Dealer();
        bool debePedirCarta() const;
    };

#endif
