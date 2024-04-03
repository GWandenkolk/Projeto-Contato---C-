// -*- coding: utf-8 -*-
#include <iostream>
#include <vector>
#include <string>
#include <ctime>


using namespace std;

// Definição da classe Data
class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    // Construtor
    Data(int d, int m, int a) : dia(d), mes(m), ano(a) {}

    // Getters e Setters
    int getDia() const { return dia; }
    void setDia(int d) { dia = d; }

    int getMes() const { return mes; }
    void setMes(int m) { mes = m; }

    int getAno() const { return ano; }
    void setAno(int a) { ano = a; }
};

// Definição da classe Contato
class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:
    // Construtor
    Contato(string e, string n, string tel, Data dt) : email(e), nome(n), telefone(tel), dtnasc(dt) {}

    // Método para calcular a idade
    int idade() const {
        time_t now = time(0);
        tm* localTime = localtime(&now);
        int anoAtual = 1900 + localTime->tm_year;
        int idade = anoAtual - dtnasc.getAno();
        if (localTime->tm_mon < dtnasc.getMes() || (localTime->tm_mon == dtnasc.getMes() && localTime->tm_mday < dtnasc.getDia())) {
            idade--;
        }
        return idade;
    }

    // Getters e Setters
    string getEmail() const { return email; }
    void setEmail(string e) { email = e; }

    string getNome() const { return nome; }
    void setNome(string n) { nome = n; }

    string getTelefone() const { return telefone; }
    void setTelefone(string tel) { telefone = tel; }

    Data getDataNascimento() const { return dtnasc; }
    void setDataNascimento(Data dt) { dtnasc = dt; }
};

// Função para cadastrar contatos
Contato cadastrarContato() {
    string email, nome, telefone;
    int dia, mes, ano;
    
    cout << "Digite o email do contato: ";
    cin >> email;
    cout << "Digite o nome do contato: ";
    cin >> nome;
    cout << "Digite o telefone do contato: ";
    cin >> telefone;
    cout << "Digite o dia de nascimento do contato: ";
    cin >> dia;
    cout << "Digite o mês de nascimento do contato: ";
    cin >> mes;
    cout << "Digite o ano de nascimento do contato: ";
    cin >> ano;

    Data dtnasc(dia, mes, ano);
    return Contato(email, nome, telefone, dtnasc);
}

// Função para exibir contatos
void exibirContatos(const vector<Contato>& contatos) {
    cout << "\nLista de Contatos:\n";
    for (size_t i = 0; i < contatos.size(); ++i) {
        const Contato& contato = contatos[i];
        cout << "Nome: " << contato.getNome() << endl;
        cout << "Email: " << contato.getEmail() << endl;
        cout << "Telefone: " << contato.getTelefone() << endl;
        cout << "Idade: " << contato.idade() << endl;
        cout << "-------------------\n";
    }
}


int main() {
    vector<Contato> contatos;
    for (int i = 0; i < 5; ++i) {
        cout << "\nDigite as informações do contato " << i + 1 << endl;
        Contato novoContato = cadastrarContato();
        contatos.push_back(novoContato);
    }
    exibirContatos(contatos);

    return 0;
}
