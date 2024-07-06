#pragma once
class cJuego {
protected:
    int x, y;

public:
    cJuego(int x, int y);
    virtual void pintar() = 0;
    virtual void borrar() = 0;
    virtual void mover() = 0;
    int X() const{ return x; }
    int Y()const { return y; }
};


