# Resumen del Proyecto: ex02
Generado el: 2026-06-30 11:41:02

## Estructura de Archivos Incluidos
```
  - ex02/Account.hpp
  - ex02/tests.cpp
  - ex02/19920104_091532.log
  - ex02/Account.cpp
  - ex02/Makefile
```

## Contenido de los Archivos

### Archivo: `ex02/Account.hpp`
```hpp
// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );

	Account( int initial_deposit );
	~Account( void );

	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */

```

### Archivo: `ex02/tests.cpp`
```cpp
// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

```

### Archivo: `ex02/19920104_091532.log`
```log
[19920104_091532] index:0;amount:42;created
[19920104_091532] index:1;amount:54;created
[19920104_091532] index:2;amount:957;created
[19920104_091532] index:3;amount:432;created
[19920104_091532] index:4;amount:1234;created
[19920104_091532] index:5;amount:0;created
[19920104_091532] index:6;amount:754;created
[19920104_091532] index:7;amount:16576;created
[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
[19920104_091532] index:1;amount:54;deposits:0;withdrawals:0
[19920104_091532] index:2;amount:957;deposits:0;withdrawals:0
[19920104_091532] index:3;amount:432;deposits:0;withdrawals:0
[19920104_091532] index:4;amount:1234;deposits:0;withdrawals:0
[19920104_091532] index:5;amount:0;deposits:0;withdrawals:0
[19920104_091532] index:6;amount:754;deposits:0;withdrawals:0
[19920104_091532] index:7;amount:16576;deposits:0;withdrawals:0
[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
[19920104_091532] index:1;p_amount:54;deposit:765;amount:819;nb_deposits:1
[19920104_091532] index:2;p_amount:957;deposit:564;amount:1521;nb_deposits:1
[19920104_091532] index:3;p_amount:432;deposit:2;amount:434;nb_deposits:1
[19920104_091532] index:4;p_amount:1234;deposit:87;amount:1321;nb_deposits:1
[19920104_091532] index:5;p_amount:0;deposit:23;amount:23;nb_deposits:1
[19920104_091532] index:6;p_amount:754;deposit:9;amount:763;nb_deposits:1
[19920104_091532] index:7;p_amount:16576;deposit:20;amount:16596;nb_deposits:1
[19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0
[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
[19920104_091532] index:1;amount:819;deposits:1;withdrawals:0
[19920104_091532] index:2;amount:1521;deposits:1;withdrawals:0
[19920104_091532] index:3;amount:434;deposits:1;withdrawals:0
[19920104_091532] index:4;amount:1321;deposits:1;withdrawals:0
[19920104_091532] index:5;amount:23;deposits:1;withdrawals:0
[19920104_091532] index:6;amount:763;deposits:1;withdrawals:0
[19920104_091532] index:7;amount:16596;deposits:1;withdrawals:0
[19920104_091532] index:0;p_amount:47;withdrawal:refused
[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
[19920104_091532] index:2;p_amount:1521;withdrawal:657;amount:864;nb_withdrawals:1
[19920104_091532] index:3;p_amount:434;withdrawal:4;amount:430;nb_withdrawals:1
[19920104_091532] index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1
[19920104_091532] index:5;p_amount:23;withdrawal:refused
[19920104_091532] index:6;p_amount:763;withdrawal:657;amount:106;nb_withdrawals:1
[19920104_091532] index:7;p_amount:16596;withdrawal:7654;amount:8942;nb_withdrawals:1
[19920104_091532] accounts:8;total:12442;deposits:8;withdrawals:6
[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
[19920104_091532] index:1;amount:785;deposits:1;withdrawals:1
[19920104_091532] index:2;amount:864;deposits:1;withdrawals:1
[19920104_091532] index:3;amount:430;deposits:1;withdrawals:1
[19920104_091532] index:4;amount:1245;deposits:1;withdrawals:1
[19920104_091532] index:5;amount:23;deposits:1;withdrawals:0
[19920104_091532] index:6;amount:106;deposits:1;withdrawals:1
[19920104_091532] index:7;amount:8942;deposits:1;withdrawals:1
[19920104_091532] index:0;amount:47;closed
[19920104_091532] index:1;amount:785;closed
[19920104_091532] index:2;amount:864;closed
[19920104_091532] index:3;amount:430;closed
[19920104_091532] index:4;amount:1245;closed
[19920104_091532] index:5;amount:23;closed
[19920104_091532] index:6;amount:106;closed
[19920104_091532] index:7;amount:8942;closed

```

### Archivo: `ex02/Account.cpp`
```cpp
#include "Account.hpp"
#include <iostream>
#include <ctime>


// 1. La inicialización a 0 de las 4 variables estáticas globales del banco.

// 2. El Constructor que gestiona la apertura de las cuentas e incrementa los totales generales.

// 3. El Destructor que descuenta el saldo y las cuentas al cerrarse.

// 4. Los 4 Getters estáticos para informar al main.

// 5. displayAccountsInfos y displayStatus para volcar los datos formateados.

// 6. makeDeposit y makeWithdrawal con la gestión de balances.

// 7. Tu función _displayTimestamp.


// inicializacion de variables/atributos

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


//constructor
Account::Account(int initial_deposit){
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
			<< ";amount:" << this->_amount << ";created" << std::endl;
}

//destructor
Account::~Account(){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" 
			<< this->_amount << ";closed" << std::endl;
	this->_nbAccounts--;
	_totalAmount -= this->_amount;
}

//-----GETTERS-------

int Account::getNbAccounts(){
	return (_nbAccounts);
}
int Account::getNbDeposits(){
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(){
	return (_totalNbWithdrawals);
}

int Account::getTotalAmount(){
	return (_totalAmount);
}


// Su objetivo es pintar en la terminal una línea que resuma el estado de todo el banco en ese instante preciso
void Account::displayAccountsInfos(){
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount 
			<< ";deposits:" << _totalNbDeposits 
			<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}


void Account::makeDeposit(int deposit){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex              //1. IMPRIMIR:  "index:0;p_amount:100;deposit:50" -> (El cursor se queda esperando al final)
			<< ";p_amount:" << this->_amount
			<< ";deposit:" << deposit;

	this->_amount += deposit;
	_nbDeposits++;                                            //2. CALCULAR:  _amount pasa de 100 a 150 en la memoria RAM
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";amount:" << this->_amount 
			<< ";nb_deposits:" << this->_nbDeposits          //3. IMPRIMIR:  ";amount:150;nb_deposits:1"        -> (Se pega a lo anterior)
			<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;      // 1. Mostrar la primera parte del mensaje (Identidad y saldo previo)

	if (withdrawal > this->_amount){
		std::cout << ";withdrawal:refused" << std::endl;                                // 2. Comprobar si hay suficiente dinero (Control de errores)
		return (false);
	}
	else{
		std::cout << ";withdrawal:" << withdrawal;
		this->_amount -= withdrawal;                                                    // 3. Si llega aquí, el retiro SÍ es válido. Hacer los cálculos:
		this->_nbWithdrawals++;

		_totalAmount -= withdrawal;                                                     // 4. Actualizar las estadísticas globales del BANCO (Estáticas)
		_totalNbWithdrawals++;

		std::cout << ";amount:" << _amount 
				<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;             // 5. Mostrar el resultado final en la misma línea
	}
	return (true);
}

void Account::_displayTimestamp(){
	std::time_t	finalTime = time(NULL);
	std::tm *tme = std::localtime(&finalTime);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", tme);
	std::cout << buffer << " ";
}

void Account::displayStatus() const{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount 
			<< ";deposits:" << _nbDeposits 
			<< ";withdrawals:" << _nbWithdrawals << std::endl;
}
```

### Archivo: `ex02/Makefile`
```
# Name of executable
NAME = bank

# Compilation flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Sources
SRCS = Account.cpp tests.cpp 
OBJS = $(SRCS:.cpp=.o)

# Main rule
all: $(NAME)

# Executablee compilation
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

