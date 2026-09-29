#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Parte 1: escreva aqui as classes Astronauta, Voo e Agencia.
// Depois, em cada comando, apague a linha do cout com "TODO" e descomente
// a chamada ao metodo da Agencia.

class Astronauta {

private:
    string cpf;
    string nome;
    int idade;
    bool vivo;
    bool disponivel;

public:
    Astronauta(string cpf, string nome, int idade);

    string getCpf();
    string getNome();
    int getIdade();
    bool estaVivo();
    bool estaDisponivel();

    void embarcar();
    void desembarcar();
    void morrer();
};

Astronauta::Astronauta(string cpf, string nome, int idade) {

    this->cpf = cpf;
    this->nome = nome;
    this->idade = idade;
    this->vivo = true;
    this->disponivel = true;

}

string Astronauta::getCpf() {

    return cpf;

}

string Astronauta::getNome() {

    return nome;

}

int Astronauta::getIdade() {

    return idade;

}

bool Astronauta::estaVivo() {

    return vivo;

}

bool Astronauta::estaDisponivel() {

    return disponivel;

}

void Astronauta::embarcar() {

    disponivel = false;

}

void Astronauta::desembarcar() {

    if (vivo) {
        disponivel = true;
    }

}

void Astronauta::morrer() {

    vivo = false;
    disponivel = false;

}


class Voo {

private:
    int codigo;
    string estado;
    vector<string> cpfs;

public:
    Voo(int codigo);

    int getCodigo();
    string getEstado();
    int getQuantidadeAstronautas();
    string getCpf(int posicao);
    bool temAstronauta(string cpf);

    void adicionarAstronauta(string cpf);
    bool removerAstronauta(string cpf);

    void lancar();
    void explodir();
    void finalizar();
};

Voo::Voo(int codigo) {

    this->codigo = codigo;
    this->estado = "planejado";

}

int Voo::getCodigo() {

    return codigo;

}

string Voo::getEstado() {

    return estado;

}

int Voo::getQuantidadeAstronautas() {

    return cpfs.size();

}

string Voo::getCpf(int posicao) {

    return cpfs[posicao];

}

bool Voo::temAstronauta(string cpf) {

    for (string c : cpfs) {

        if (c == cpf) {
            return true;
        }

    }

    return false;

}

void Voo::adicionarAstronauta(string cpf) {

    cpfs.push_back(cpf);

}

bool Voo::removerAstronauta(string cpf) {

    for (int i = 0; i < cpfs.size(); i++) {

        if (cpfs[i] == cpf) {

            cpfs.erase(cpfs.begin() + i);
            return true;

        }

    }

    return false;

}

void Voo::lancar() {

    estado = "em curso";

}

void Voo::explodir() {

    estado = "finalizado com explosao";

}

void Voo::finalizar() {

    estado = "finalizado com sucesso";

}


class Agencia {

private:
    vector<Astronauta> astronautas;
    vector<Voo> voos;

    int buscarAstronauta(string cpf);
    int buscarVoo(int codigo);

public:
    void cadastrarAstronauta(string cpf, string nome, int idade);
    void cadastrarVoo(int codigo);

    void adicionarAstronauta(string cpf, int codigo);
    void removerAstronauta(string cpf, int codigo);

    void lancarVoo(int codigo);
    void explodirVoo(int codigo);
    void finalizarVoo(int codigo);

    void listarVoos();
    void listarMortos();
};

int Agencia::buscarAstronauta(string cpf) {

    for (int i = 0; i < astronautas.size(); i++) {

        if (astronautas[i].getCpf() == cpf) {
            return i;
        }

    }

    return -1;

}

int Agencia::buscarVoo(int codigo) {

    for (int i = 0; i < voos.size(); i++) {

        if (voos[i].getCodigo() == codigo) {
            return i;
        }

    }

    return -1;

}

void Agencia::cadastrarAstronauta(string cpf, string nome, int idade) {

    if (buscarAstronauta(cpf) != -1) {
        cout << "ERRO: astronauta com CPF " << cpf << " ja cadastrado" << endl;
        return;
    }

    astronautas.push_back(Astronauta(cpf, nome, idade));

    cout << "OK: astronauta " << cpf << " cadastrado" << endl;

}

void Agencia::cadastrarVoo(int codigo) {

    if (buscarVoo(codigo) != -1) {
        cout << "ERRO: voo " << codigo << " ja cadastrado" << endl;
        return;
    }

    voos.push_back(Voo(codigo));

    cout << "OK: voo " << codigo << " cadastrado" << endl;

}

void Agencia::adicionarAstronauta(string cpf, int codigo) {

    int posA = buscarAstronauta(cpf);

    if (posA == -1) {
        cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
        return;
    }

    int posV = buscarVoo(codigo);

    if (posV == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }

    if (voos[posV].getEstado() != "planejado") {
        cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
        return;
    }

    if (!astronautas[posA].estaVivo()) {
        cout << "ERRO: astronauta " << cpf << " esta morto" << endl;
        return;
    }

    if (voos[posV].temAstronauta(cpf)) {
        cout << "ERRO: astronauta " << cpf << " ja esta no voo " << codigo << endl;
        return;
    }

    voos[posV].adicionarAstronauta(cpf);

    cout << "OK: astronauta " << cpf << " adicionado ao voo " << codigo << endl;

}

void Agencia::removerAstronauta(string cpf, int codigo) {

    int posA = buscarAstronauta(cpf);

    if (posA == -1) {
        cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
        return;
    }

    int posV = buscarVoo(codigo);

    if (posV == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }

    if (voos[posV].getEstado() != "planejado") {
        cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
        return;
    }

    if (!voos[posV].temAstronauta(cpf)) {
        cout << "ERRO: astronauta " << cpf << " nao esta no voo " << codigo << endl;
        return;
    }

    voos[posV].removerAstronauta(cpf);

    cout << "OK: astronauta " << cpf << " removido do voo " << codigo << endl;

}

void Agencia::lancarVoo(int codigo) {

    int posV = buscarVoo(codigo);

    if (posV == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }

    if (voos[posV].getEstado() != "planejado") {
        cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
        return;
    }

    if (voos[posV].getQuantidadeAstronautas() == 0) {
        cout << "ERRO: voo " << codigo << " nao possui astronautas" << endl;
        return;
    }

    for (int i = 0; i < voos[posV].getQuantidadeAstronautas(); i++) {

        string cpf = voos[posV].getCpf(i);

        int posA = buscarAstronauta(cpf);

        if (!astronautas[posA].estaVivo()) {
            cout << "ERRO: astronauta " << cpf << " esta morto" << endl;
            return;
        }

        if (!astronautas[posA].estaDisponivel()) {
            cout << "ERRO: astronauta " << cpf << " esta indisponivel" << endl;
            return;
        }

    }

    for (int i = 0; i < voos[posV].getQuantidadeAstronautas(); i++) {

        string cpf = voos[posV].getCpf(i);

        int posA = buscarAstronauta(cpf);

        astronautas[posA].embarcar();

    }

    voos[posV].lancar();

    cout << "OK: voo " << codigo << " lancado" << endl;

}

void Agencia::explodirVoo(int codigo) {

    int posV = buscarVoo(codigo);

    if (posV == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }

    if (voos[posV].getEstado() != "em curso") {
        cout << "ERRO: voo " << codigo << " nao esta em curso" << endl;
        return;
    }

    voos[posV].explodir();

    for (int i = 0; i < voos[posV].getQuantidadeAstronautas(); i++) {

        string cpf = voos[posV].getCpf(i);

        int posA = buscarAstronauta(cpf);

        astronautas[posA].morrer();

    }

    cout << "OK: voo " << codigo << " explodiu" << endl;

}

void Agencia::finalizarVoo(int codigo) {

    int posV = buscarVoo(codigo);

    if (posV == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }

    if (voos[posV].getEstado() != "em curso") {
        cout << "ERRO: voo " << codigo << " nao esta em curso" << endl;
        return;
    }

    voos[posV].finalizar();

    for (int i = 0; i < voos[posV].getQuantidadeAstronautas(); i++) {

        string cpf = voos[posV].getCpf(i);

        int posA = buscarAstronauta(cpf);

        astronautas[posA].desembarcar();

    }

    cout << "OK: voo " << codigo << " finalizado com sucesso" << endl;

}

int main() {
    // TODO: criar a Agencia aqui, por exemplo:  Agencia agencia;
    string comando;

    while (cin >> comando) {   // le uma palavra; para no FIM ou quando a entrada acaba
        if (comando == "FIM") {
            break;
        } else if (comando == "CADASTRAR_ASTRONAUTA") {
            string cpf, nome;
            int idade;
            cin >> cpf >> idade;
            getline(cin >> ws, nome);   // o nome vem por ultimo e pode ter espacos
            cout << "TODO " << comando << endl;
            // TODO: agencia.cadastrarAstronauta(cpf, nome, idade);
        } else if (comando == "CADASTRAR_VOO") {
            int codigo;
            cin >> codigo;
            cout << "TODO " << comando << endl;
            // TODO: agencia.cadastrarVoo(codigo);
        } else if (comando == "ADICIONAR_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            cout << "TODO " << comando << endl;
            // TODO: agencia.adicionarAstronauta(cpf, codigo);
        } else if (comando == "REMOVER_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            cout << "TODO " << comando << endl;
            // TODO: agencia.removerAstronauta(cpf, codigo);
        } else if (comando == "LANCAR_VOO") {
            int codigo;
            cin >> codigo;
            cout << "TODO " << comando << endl;
            // TODO: agencia.lancarVoo(codigo);
        } else if (comando == "EXPLODIR_VOO") {
            int codigo;
            cin >> codigo;
            cout << "TODO " << comando << endl;
            // TODO: agencia.explodirVoo(codigo);
        } else if (comando == "FINALIZAR_VOO") {
            int codigo;
            cin >> codigo;
            cout << "TODO " << comando << endl;
            // TODO: agencia.finalizarVoo(codigo);
        } else if (comando == "LISTAR_VOOS") {
            cout << "TODO " << comando << endl;
            // TODO: agencia.listarVoos();
        } else if (comando == "LISTAR_MORTOS") {
            cout << "TODO " << comando << endl;
            // TODO: agencia.listarMortos();
        } else {
            cout << "ERRO: comando desconhecido " << comando << endl;
        }
    }

    return 0;
}
