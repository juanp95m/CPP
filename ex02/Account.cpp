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
