#include "PiezaVerde.h"

PiezaVerde::PiezaVerde()
{

}

PiezaVerde::PiezaVerde(int pColor) : Pieza(pColor)
{

}

int PiezaVerde::EntrarTablero()
{
  dentro = 1;
  x = 0;
  y = 0;
  return 0;
}

int PiezaVerde::ZonaFinal()
{
  finalZ = 1;
  return 0;
}

int PiezaVerde::mover(int dado)
{
  if (x==7 && y==7) {
		//cout << "La pieza ya esta en el centro" << endl;
		return 1;
	}
  else if (x==0 && y==7) {
    int sumaX = x + dado;
    if (sumaX>7){
      x = 7;
      return 1;
    }
    else {
      x +=dado;
      return 0;
    }
  }
	else{
		if (y==0) {//condiciones de y=0
			int sumaX = x + dado;
			if (sumaX>14){
				int restaX = 14 - x;
				x += restaX;
				dado -= restaX;
				return mover(dado);
			}
      else {
        x+=dado;
        return 0;
      }
		}//fin de la condicion y=0
    if (x==14){//condicion de x=14
      int sumaY = y + dado;
      if (sumaY>14) {
        int restaY = 14 - y;
        y += restaY;
        dado -= restaY;
        return mover(dado);
      }
      else {
        y+=dado;
        return 0;
      }
    }//fin de la condicion de x==14
    if (y==14) {// condicion cuando y = 14
      int restaX = x-dado;
      if (restaX<0){
        x = 0;
        dado -=x;
        return mover(dado);
      }
      else {
        x-=dado;
        return 0;
      }
    }//fin de la condicion de y=14
    if (x==0) {//condicion cuando x = 0;
      int restaY = y - dado;
      if (restaY<0) {
        y = 0;
        dado -=y;
        return mover(dado);
      }
      else {
        y-=dado;
        return 0;
      }
    }//fin de la condicion de x = 0
	}
}

int PiezaVerde::SalirTablero()
{
  dentro = finalZ = 0;
  x=0;
  y=0;
  return 0;
}
