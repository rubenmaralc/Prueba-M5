// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

//Atributos del enemigo
int enemyHP = 100;
string enemyName = "Creeper";
bool enemyIsAlive = true;
int enemyDamage;



//Atributos de héroe
string heroName;
int heroDamage;
int heroHP = 500;
bool heroisAlive = true;


void startGame() { //void no devuelve nada.//esto es una funcion.
    cout << "Un " << enemyName << " acabada de aparecer y tiene " << enemyHP << " HP de vida\n";
    cout << "Como se llama el heroe?\n";
    cin >> heroName;
    cout << "El nombre del heroe es " << heroName << "\n";
}

int heroAttack() {
    return enemyHP - heroDamage; //return es necesario cuando nos tiene que devolver algo la funcion.
}

boolean statusEnemy() {
    if (enemyHP <= 0) {
        //Playsoun(TEXT("Sonido.wav"),NULL)
        cout << "Te acabas de cargar al enemigo " << enemyName << "\n";
        return false;
    }
    else {
        cout << "Al " << enemyName << " le quedan " << enemyHP << " puntos de vida\n";
        return true;
        //isAlive = true;
    }
}

boolean statusHero() {
    if (heroHP <= 0) {
        heroHP = 0;
        cout << "El enemigo " << enemyName << " te ha matado\n";
        return false;
    }
    else {
        cout << "El enemigo " << enemyName << " te ha hecho un ataque de " << enemyDamage << " puntos de pupita y te quedan " << heroHP << " puntos de vida\n";
        return true;
    }
}

int enemyAttack(int damage) {
    return heroHP - damage;
}

int main()
{
    srand(time(NULL));

    startGame();
    
    while (enemyIsAlive && heroisAlive)
    {
        cout << "Cuanta pupita quieres hacer al " << enemyName << "?\n";
        cin >> heroDamage;
        enemyHP = heroAttack();
        enemyIsAlive = statusEnemy();

        if (enemyIsAlive) {
            //Ataque al heroe
            enemyDamage = rand() % 80 + 1;
            heroHP = enemyAttack(100);
            heroisAlive = statusHero();
        }
        //if (statusEnemy())
        //{
        //    //Ataque al heroe
        //    enemyDamage = rand() % 80 + 1;
        //    heroHP = enemyAttack(100);
        //    heroisAlive = statusHero();
        //} esto hace lo mismo que el if anterior.
    }  
    //las bolas rojas del lateral izquierdo son puntos de ruptura. La ejecución se para en cada linea que hemos marcado.
    // si entramos en el código podemos ver los valores de las variables que se van a ejecutar.
    // botones de flechas
    //pasa a paso por instrucciones: va linea a linea, en una funcion se va a la funcion.
    //Paso a paso por procedimientos: va linea a linea, ejecutando las funciones sin entrar en ellas. 
    //paso a paso para salir: te saca del procedimiento actual
}


