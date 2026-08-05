#include <iostream>
#include <vector>

using namespace std;

class ItemBiblioteca {
protected:
    int id_, ano_;
    string titulo_;
    bool emprestado_;

public:
	ItemBiblioteca(int id, string titulo, int ano);

    virtual void exibirDetalhes();
    int getId();
    bool isEmprestado();
    void emprestar();
    void devolver();
};

class Livro : public ItemBiblioteca {
protected:
	string autor_;
	string genero_;

public:
    Livro(int id, string titulo, int ano, string autor, string genero);
    Livro() : ItemBiblioteca(0, "", 0), autor_(""), genero_("") {} // Construtor padrão
    void exibirDetalhes(); 
};

class Usuario {
protected:
    int id_, limiteEmprestimos_, emprestimosAtuais_;
    string nome_;

public:
    Usuario(int id, string nome, int limiteEmprestimos);

    virtual void exibirUsuario();
    bool podeEmprestar();
    void realizarEmprestimo(); 
    void realizarDevolucao(); 
    int getId();
};

class Aluno : public Usuario {
public:
    Aluno(int id, string nome);
};

class Professor : public Usuario {
public:
    Professor(int id, string nome);
};

class Biblioteca {
    vector<Livro> livros;
    vector<Aluno> alunos;
    vector<Professor> professores;

public:
    void adicionarLivro();
    void listarLivros();
    void adicionarUsuario();
    void listarUsuarios();
    void emprestarLivro();
    void devolverLivro();
    void menu();
};

int main() {
	setlocale(LC_ALL, "Portuguese"); 
	int escolha;
	
	Biblioteca minhaBiblioteca;


	while (true) {
			minhaBiblioteca.menu();
			cout << "Escolha uma opção: ";
			cin >> escolha;	
			cout << " " << endl;

		if (escolha == 0){
			cout << "--------------------------------" << endl;
			cout << "Você saiu do programa. \n";
				break;
		}

			switch(escolha){
				case 1:
				cout << "--------- Adicionar Livro ---------" << endl;
				minhaBiblioteca.adicionarLivro();
				break;

				case 2:
				cout << "--------- Listagem de Livros ---------" << endl;
				minhaBiblioteca.listarLivros();
				break;

				case 3:
				cout << "--------- Adicionar Usuário ---------" << endl;
				minhaBiblioteca.adicionarUsuario();
				break;

				case 4:
				minhaBiblioteca.listarUsuarios();
				break;

				case 5:
				cout << "--------- Emprestar Livro ---------" << endl;
				minhaBiblioteca.emprestarLivro();
				break;

				case 6:
				cout << "--------- Devolver Livro ---------" << endl;
				minhaBiblioteca.devolverLivro();
				break;

				default:
				cout << "Opção inválida!" << endl;
				break;
		}
	}
}

// construtores

ItemBiblioteca::ItemBiblioteca (int id, string titulo, int ano):
	id_(id), ano_(ano), titulo_(titulo), emprestado_(false){}

Livro::Livro (int id, string titulo, int ano, string autor, string genero):
	ItemBiblioteca (id, titulo, ano), autor_(autor), genero_(genero){}

Usuario::Usuario(int id, string nome, int limiteEmprestimos):
	id_(id), nome_(nome), limiteEmprestimos_(limiteEmprestimos), emprestimosAtuais_(0){}

Aluno::Aluno(int id, string nome):
	Usuario(id, nome, 3){}

Professor::Professor (int id, string nome):
	Usuario (id, nome, 5){}

//métodos de ItemBiblioteca

void ItemBiblioteca::exibirDetalhes() { 
	cout << "ID: " << id_ << endl;
	cout << "Título: " << titulo_ << endl;
	cout << "Ano: " << ano_ << endl;
	cout << "Emprestado: ";
	if (emprestado_) {
		cout << "Sim" << endl;
	}
	else {
		cout << "Não" << endl;
	}
};

int ItemBiblioteca::getId() { 
	return id_;
};

bool ItemBiblioteca::isEmprestado() {
	return emprestado_;
};

void ItemBiblioteca::emprestar() { 
	if(emprestado_) {
		cout << "O item não está disponível." << endl;
	}
	else {
		cout << "Item " << id_ << " emprestado." << endl;
		emprestado_ = true;
	}
};

void ItemBiblioteca::devolver() {
	if (emprestado_) {
	  	cout << "Item " << id_ << " devolvido." << endl;
        emprestado_ = false;
	}
	else {
    	cout << "O item já está disponível." << endl;
    }
};

// métodos de Livro

void Livro::exibirDetalhes(){
	cout << "ID: " << id_ << endl;
	cout << "Título: " << titulo_ << endl;
	cout << "Autor: " << autor_ << endl;
	cout << "Gênero: " << genero_ << endl;
	cout << "Ano: " << ano_ << endl;
	cout << "Emprestado: ";
	if (emprestado_) {
		cout << "Sim" << endl;
	}
	else {
		cout << "Não" << endl;
	}
};

// métodos de Usuário

void Usuario::exibirUsuario() {
	cout << "Id: " << id_ << endl;
	cout << "Nome: " << nome_ << endl;
	cout << "Limite de empréstimos: " << limiteEmprestimos_ << endl;
	cout << "Empréstimos atuais: " << emprestimosAtuais_ << endl;
};

bool Usuario::podeEmprestar() {
    return emprestimosAtuais_ < limiteEmprestimos_;
};

void Usuario::realizarEmprestimo() {
	if (podeEmprestar()) {
		limiteEmprestimos_--;
		emprestimosAtuais_++;
	}
};

void Usuario::realizarDevolucao() {
    if (emprestimosAtuais_ > 0) {
        limiteEmprestimos_++;
        emprestimosAtuais_--;
    }
};

int Usuario::getId() {
	return id_;
};

// métodos de Biblioteca

void Biblioteca::adicionarLivro() {
		string titulo, autor, genero;
    	int id, ano; 

    	cout << "Digite o ID: ";
		cin >> id;
		cin.ignore();
		cout << "Digite o título do livro: ";
    	getline(cin, titulo); //para permitir espaços
		cout << "Digite o ano do livro: ";
    	cin >> ano;
    	cin.ignore();
		cout << "Digite o autor do livro: ";
    	getline(cin, autor);
    	cout << "Digite o gênero do livro: ";
    	getline(cin, genero);

    	livros.push_back(Livro(id, titulo, ano, autor, genero)); 

		cout << "Livro cadastrado com sucesso! \n" << endl;
};

void Biblioteca::listarLivros(){
	for (int i = 0; i < livros.size(); ++i) {
        livros[i].exibirDetalhes(); 
        cout << " " << endl;
    }
};

void Biblioteca::adicionarUsuario(){
    	string tipo, nome;
    	int id; 
    	cout << "Digite o ID: ";
    	cin >> id;
    	cin.ignore();
    	cout << "Digite o nome: ";
    	getline(cin, nome);
    	cout << "Tipo (Aluno/Professor): ";
    	cin >> tipo;
    	
    	if (tipo == "Aluno"){
    		alunos.push_back(Aluno(id, nome)); 
		}
    	if (tipo == "Professor"){
    		professores.push_back(Professor(id, nome));
		}

		cout << "Usuário cadastrado com sucesso! \n" << endl;
		cout << " " << endl;
};

void Biblioteca::listarUsuarios(){
    cout << "--------- Lista de Alunos ---------" << endl;
    for (int i = 0; i < alunos.size(); ++i) { // alunos.size() é um método da classe vector que retorna o número de elementos no vetor alunos
        alunos[i].exibirUsuario();
        cout << " " << endl;
	}

    cout << "--------- Lista de Professores ---------" << endl;
    for (int i = 0; i < professores.size(); ++i) {
        professores[i].exibirUsuario();
    }
    cout << " " << endl;
};

void Biblioteca::emprestarLivro(){
	int livro_id, usuario_id;
	    
    cout << "Digite o ID do livro: ";
    cin >> livro_id;
    cout << "Digite o ID do usuário: ";
    cin >> usuario_id;

    for (int i = 0; i < livros.size(); ++i) {
        if (livros[i].getId() == livro_id) {
            if (livros[i].isEmprestado()) {
                cout << "O livro está emprestado. \n" << endl;
                return;
            }

            for (int j = 0; j < alunos.size(); ++j) {
                if (alunos[j].getId() == usuario_id) {
                    if (alunos[j].podeEmprestar()) {
                        livros[i].emprestar();
                        alunos[j].realizarEmprestimo();
                        cout << "Empréstimo realizado com sucesso! \n" << endl;
                        return;
                    } 
					else {
                        cout << "Usuário atingiu o limite de empréstimos. \n" << endl;
                        return;
                    }
                }
            }
            
            for (int j = 0; j < professores.size(); ++j) {
                if (professores[j].getId() == usuario_id) {
                    if (professores[j].podeEmprestar()) {
                        livros[i].emprestar();
                        professores[j].realizarEmprestimo();
                        cout << "Empréstimo realizado com sucesso! \n" << endl;
                        return;
                    } 
					else {
                        cout << "Usuário atingiu o limite de empréstimos. \n" << endl;
                        return;
                    }
                }
            }
            cout << "Usuário não encontrado. \n" << endl;
            cout << " " << endl;
            return;
        }
    }
    cout << "Livro não encontrado. \n" << endl;
};

void Biblioteca::devolverLivro(){
	int livro_id, usuario_id;
	
    cout << "Digite o ID do livro: ";
    cin >> livro_id;
    cout << "Digite o ID do usuário: ";
    cin >> usuario_id;

    for (int i = 0; i < livros.size(); ++i) {
        if (livros[i].getId() == livro_id) {
            if (!livros[i].isEmprestado()) { //!livros - operador NOT
                cout << "O livro não está emprestado. \n" << endl;
                return;
            }

            for (int j = 0; j < alunos.size(); ++j) {
                if (alunos[j].getId() == usuario_id) {
                    livros[i].devolver();
                    alunos[j].realizarDevolucao();
                    cout << "Devolução realizada com sucesso! \n" << endl;
					return;
			    	} 
            }
            for (int j = 0; j < professores.size(); ++j) {
                if (professores[j].getId() == usuario_id) {
                    livros[i].devolver();
                    professores[j].realizarDevolucao();
                    cout << "Devolução realizada com sucesso! \n" << endl;
					return;
			    } 
            }
            cout << "Usuário não encontrado. \n" << endl;
            return;
        }
    }
    cout << "Livro não encontrado. \n" << endl;
};

void Biblioteca::menu(){
	cout << "--------- Sistema de Biblioteca ---------" << endl;
	cout << "1. Adicionar Livro" << endl;
	cout << "2. Listar Livros" << endl;
	cout << "3. Adicionar usuário" << endl;
	cout << "4. Listar Usuários" << endl;
	cout << "5. Emprestar Livro" << endl;
	cout << "6. Devolver Livro" << endl;
	cout << "0. Sair \n" << endl;
};

