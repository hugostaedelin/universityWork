#include "livraison.h"

livraison::livraison() : d_fragile{false}, d_express{false}
{}

bool livraison::estExpress() const
{
    return d_express;
}

bool livraison::estFragile() const
{
    return d_fragile;
}

void livraison::rendFragile(bool f)
{
    d_fragile = f;
}

void livraison::rendExpress(bool e)
{
    d_express = e;
}

void livraison::reInitialise()
{
    d_fragile = false;
    d_express = false;
}

