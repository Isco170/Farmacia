#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <exception>

using namespace std;

class Produto{

	private:
	    string codigo;
        string nome;
        string descricao;
        string preco;

    public:
        void setCodigo(string codigo){
            this->codigo = codigo;
        }
        string getCodigo(){
            return this->codigo;
        }
        void setNome(string nome){
            this->nome = nome;
        };
        string getNome(){
            return this->nome;
        }
        void setDescricao(string descricao){
            this->descricao = descricao;
        }
        string getDescricao(){
            return this->descricao;
        }
        void setPreco(string preco){
            this->preco = preco;
        }
        string getPreco(){
            return this->preco;
        }
};

class Empregado{
    private:
    	string codigo;
        string nome;
        string apelido;
        string usuario;
        string senha;
    public:
    	void setCodigo(string codigo){
    		this->codigo = codigo;
		}
		string getCodigo(){
			return this->codigo;
		}
        void setNome(string nome){
            this->nome = nome;
        }
        string getNome(){
            return this->nome;
        }

        void setApelido(string apelido){
            this->apelido = apelido;
        }
        string getApelido(){
            return this->apelido;
        }

        void setUsuario(string usuario){
            this->usuario = usuario;
        }

        string getUsuario(){
            return this->usuario;
        }

        void setSenha(string senha){
            this->senha = senha;
        }
        string getSenha(){
            return this->senha;
        }
};

class Administrador:public Empregado{};

class Funcionario:public Empregado{};

class Operacoes{

    private:
   	 		Produto prod;
		    vector<Produto> listaProdutos;
		    vector<Funcionario> listaFuncionario;
		    Administrador admin;
		    Funcionario func;


    public:
        Produto null;
        int ad = 0;
        bool verificar = false;
        ofstream adminSaida;
        ifstream adminEntrada;
        ofstream arquivoSFunc, arquivoSProd;
        ifstream arquivoEFunc, arquivoEProd;

        void cadastroAdmin(){


            string nome, apelido, usuario, senha, senha2;
            cout <<"============================" << endl;
            cout << "CADASTRANDO AMINISTRADOR" << endl;
            cout <<"============================" << endl;

            cout <<"Ensira o Nome: ";
            cin >> nome;
            cout <<"Ensira o Apelido: ";
            cin >> apelido;
            cout <<"Ensira o Usuario: ";
            cin >> usuario;
            cout <<"Ensira a Senha: ";
            cin >> senha;
            cout <<"Confirmar a Senha: ";
            cin >> senha2;

            if(senha == senha2){
                system("CLS");
                adminSaida.open("Administrador.txt");
                adminSaida << nome <<endl <<apelido <<endl <<usuario <<endl <<senha <<endl;
                cout << "Administrador salvo!" << endl <<endl;
                login();
            }else{
                cout << "Senhas incompativeis!" <<endl << endl;
                login();
            }


        adminSaida.close();
        }
        void ficheiro(){
            arquivoEFunc.open("Funcionarios.txt");
			string codigo,nome, apelido, usuario, senha;

			if(arquivoEFunc.is_open()){

                while(!arquivoEFunc.eof()){
                        Funcionario func;

                        getline(arquivoEFunc, codigo);
                        func.setCodigo(codigo);

                        getline(arquivoEFunc, nome);
                        func.setNome(nome);

                        getline(arquivoEFunc,apelido);
                        func.setApelido(apelido);

                        getline(arquivoEFunc, usuario);
                        func.setUsuario(usuario);

                        getline(arquivoEFunc, senha);
                        func.setSenha(senha);

                        if(codigo != "")
                        listaFuncionario.push_back(func);
                    }
                    arquivoEFunc.close();
			}

			else{
               // cout << "Problemas com o ficheiro!";
			}
        }
       void ficheiroProdutos(){
            arquivoEProd.open("Produtos.txt");
			string codigo,nome, descricao, preco;

			if(arquivoEProd.is_open()){

                while(!arquivoEProd.eof()){
                        Produto prod;

                        getline(arquivoEProd, codigo);
                        prod.setCodigo(codigo);

                        getline(arquivoEProd, nome);
                        prod.setNome(nome);

                        getline(arquivoEProd,descricao);
                        prod.setDescricao(descricao);

                        getline(arquivoEProd, preco);
                        prod.setPreco(preco);

                        if(codigo != "")
                        listaProdutos.push_back(prod);
                    }
                    arquivoEProd.close();
			}

			else{
               // cout << "Problemas com o ficheiro de produtos!";
			}
       }
        Operacoes(){
            ficheiro();
            ficheiroProdutos();
        }
        void login(){
            cout << "================================" << endl;
            cout << "[1] Administrador" << endl << "[2] Funcionario" << endl;
            cout << "================================" << endl;
            int opc;
            cin >> opc;

            system("CLS");
            switch (opc){
                case 1:
                   menuAdmin();
                    break;
                case 2:
                    menuUser();
                    break;
                default:
                    cout << "Escolha incorreta!";
                    login();
            }
        }

        void menuAdmin(){

            adminEntrada.open("Administrador.txt");
            string nome, apelido, usuario, senha, username, password;
            Administrador admin;

            if(adminEntrada.is_open()){

                while(!adminEntrada.eof()){
                    getline(adminEntrada, nome);
                    admin.setNome(nome);
                    getline(adminEntrada, apelido);
                    admin.setApelido(apelido);
                    getline(adminEntrada, usuario);
                    admin.setUsuario(usuario);
                    getline(adminEntrada, senha);
                    admin.setSenha(senha);
                    break;
                }
                if(ad == 0){
                cout << "Usuario: ";
                cin >> username;
                cout << "Senha: ";
                cin >> password;
                ad=1;
                }


                if(((username == usuario) && (password == senha))|| ad==1){
                        system("CLS");
                    cout << "================================" << endl;
                    cout << "[1] Cadastrar Funcionario" << endl << "[2] Listar Funcionarios" << endl;
                    cout << "[3] Remover Funcionario" << endl;
                    cout << "[4] Cadastrar Produto" << endl;
                    cout << "[5] Listar Produto" << endl;
                    cout << "[6] Remover Produto" << endl;
                    cout << "================================" << endl;
                    int opc;
                    cin >> opc;
                    system("CLS");
                    switch (opc){
                        case 1:
                            cadastroFuncionario(); break;
                        case 2:
                            listarFuncionarios(); break;
                        case 3:
                            removerFuncionario(); break;
                        case 4:
                            cadastrarProduto(); break;

                        case 5:
                            listarProdutos(); break;

                        case 6:
                            removerProduto(); break;

                        default:
                            cout << "Escolha invalida!" << endl;
                            menuAdmin();
                        }
                }else{
                    cout << "Dados incorretos!" << endl;
                    login();
                }

            }else{
                cadastroAdmin();
            }


        }

        void menuUser(){
            string usuario, senha;
            if(verificar == false){
                    cout << "Usuario: "; cin >> usuario;
                    cout << "Senha: "; cin >> senha;
                    system("CLS");
                    for(int a = 0; a< listaFuncionario.size(); a++){
                        if((listaFuncionario.at(a).getUsuario() == usuario) && (listaFuncionario.at(a).getSenha() == senha)){
                        verificar = true; break;
                        }
                    }
            }

            if(verificar == true){

                cout << "[1] Registrar venda" << endl;
                cout << "[2] Consultar produto" << endl;
                cout << "[3] Listar produto" << endl;
                int op; cin >> op;
                switch (op){
                    case 1:
                        registarVenda(); break;
                    case 2:
                        consultarProdutos(); break;
                    case 3:
                        usuarioListarProdutos(); break;
                    default:
                        cout << "Opcao invalida!" << endl;
                        menuUser();
                   }
            }else{
                cout << "Dados incorretos!" << endl;
                login();
            }
        }

        void cadastroFuncionario(){
            arquivoSFunc.open("Funcionarios.txt", ios::app);
            if(arquivoSFunc.is_open()){

                cout << "Digite o codigo do Funcionario: " << endl;
                string codigo; cin >> codigo;

                cout << "Digite o nome do Funcionario: " << endl;
                string nome;
                cin >> nome;

                cout << "Digite o apelido do Funcionario: " << endl;
                string apelido; cin >> apelido;

                cout << "Criar usuario para " << nome << endl;
                string usuario; cin >> usuario;

                cout << "Criar senha para usuario " << usuario << endl;
                string senha; cin >> senha;

                arquivoSFunc << codigo <<endl << nome <<endl << apelido <<endl << usuario << endl << senha << endl;
                arquivoSFunc.close();
                system("CLS");
                cout << "Funcionario cadastrado!" << endl << endl;
                    char v;
                    cout << "[V]  -> VOLTAR "; cin >>v;
                    if(v=='v'){
                        system("CLS");
                        menuAdmin();
                    }
            }else{
                cout << "Ficheiro 'Funcionario' nao salvo!";
            }
        }
        void listarFuncionarios(){
			    cout << "=========================================="<< endl;
                cout << "Codigo   Nome   Apelido   Usuario   Senha" << endl;
                cout << "=========================================="<< endl;
                cout << "Total Funcionarios: " << listaFuncionario.size() <<endl ;
                for(int a =0; a< listaFuncionario.size(); a++){
                    cout <<"[" <<a+1 <<"] " <<listaFuncionario.at(a).getCodigo() <<" " << listaFuncionario.at(a).getNome() <<" " << listaFuncionario.at(a).getApelido() << endl;
                }
			cout << endl;
			cout << endl;
			char v;
			cout << "[V]  -> VOLTAR "; cin >>v;
			if(v=='v'){
                system("CLS");
                menuAdmin();
			}

        }

        void removerFuncionario(){

        	if(listaFuncionario.size() == 0)
        		cout << "Sem funcionarios!" <<endl;
        	else{
				cout << "Digite o codigo do funcionario: "<< endl; string codigo; cin >> codigo;
				cout << "Digite o nome do funcionario: "<< endl; string nome; cin >> nome;
				bool t = false;
				int posi =0;

				for(int a=0; a<= listaFuncionario.size(); a++){
					if(listaFuncionario.at(a).getCodigo() == codigo){
                            posi = a; t = true;break;
                    }
				}
				if( t == true){
                    try{
                        listaFuncionario.erase(listaFuncionario.begin()+ (posi));

                        cout << nome << " removido!" << endl;

                        arquivoSFunc.open("Funcionarios.txt");
                        if(arquivoSFunc.is_open()){
                            string codigo;
                            string nome;
                            string apelido;
                            string usuario;
                            string senha;

                            for(int a = 0; a <listaFuncionario.size(); a++){
                                codigo = listaFuncionario.at(a).getCodigo();
                                nome = listaFuncionario.at(a).getNome();
                                apelido = listaFuncionario.at(a).getApelido();
                                usuario = listaFuncionario.at(a).getUsuario();
                                senha = listaFuncionario.at(a).getSenha();

                                arquivoSFunc << codigo <<endl << nome <<endl << apelido <<endl << usuario << endl << senha << endl;
                            }
                            arquivoSFunc.close();

                        }
                    }catch(exception& e){
                           // cout << "Erro: " << e.what() <<endl;
                        }
				}else{
                    cout << "Funcionario nao encontrado!" << endl;
				}					}
					char v;
                    cout << "[V]  -> VOLTAR "; cin >>v;
                    if(v=='v'){
                        system("CLS");
                        menuAdmin();
                    }
			}


		void cadastrarProduto(){
		    arquivoSProd.open("Produtos.txt", ios::app);
		    if(arquivoSProd.is_open()){
                cout << "Codigo do produto: "; string codigo; cin >> codigo;
                cout << "Nome do produto: "; string nome; cin >> nome;
                cout << "Descricao do produto: "; string descricao; cin >> descricao;
                cout <<"Preco: "; string preco; cin >> preco;

                arquivoSProd << codigo <<endl << nome << endl << descricao << endl << preco <<endl;
                arquivoSProd.close();
                system("CLS");
                cout <<"Produto cadastrado!" << endl;
                char v;
                    cout << "[V]  -> VOLTAR "; cin >>v;
                    if(v=='v'){
                        system("CLS");
                        menuAdmin();
                    }

		    }else{
                cout <<"ficheiro produto com problemas!" << endl;
		    }

		}
		void listarProdutos(){
			if(listaProdutos.size() == 0){
                system("CLS");
				cout << "Nao existem Produtos!" << endl;

			}else{
                cout << "=========================================="<< endl;
                cout << "Codigo    Nome    Descricao    Preco" << endl;
                cout << "=========================================="<< endl;
                cout << "Total Produtos: " << listaProdutos.size() <<endl ;
                for(int a =0; a< listaProdutos.size(); a++){
                    cout <<"[" <<a+1 <<"] " <<listaProdutos.at(a).getCodigo() <<"  " << listaProdutos.at(a).getNome() <<"  " << listaProdutos.at(a).getDescricao() << "  " << listaProdutos.at(a).getPreco()<<endl;
                }
                cout << endl;
                cout << endl;
            }
            char v;
                cout << "[V]  -> VOLTAR "; cin >>v;
                    if(v=='v'){
                    system("CLS");
                    menuAdmin();
                }
        }

		void removerProduto(){
		    if(listaProdutos.size() == 0)
                cout << "Nao existem produtos para remover!" << endl << endl;
            else{

                cout << "Codigo do produto: "; string codigo; cin >> codigo;
                cout << "Nome do produto: "; string nome; cin >> nome;
                system("CLS");
                int posi = 0;
                bool t = false;

                for(int a=0; a<= listaProdutos.size(); a++){
                    if((listaProdutos.at(a).getCodigo() == codigo) && (listaProdutos.at(a).getNome() == nome)){
                        posi = a; t = true; break;
                    }
                }
                if( t == true){
                    try{
                        listaProdutos.erase(listaProdutos.begin()+ (posi));

                        cout << nome << " removido!" << endl;

                        arquivoSProd.open("Produtos.txt");
                        if(arquivoSProd.is_open()){
                            string codigo;
                            string nome;
                            string descricao;
                            string preco;

                            for(int a = 0; a <listaProdutos.size(); a++){
                                codigo = listaProdutos.at(a).getCodigo();
                                nome = listaProdutos.at(a).getNome();
                                descricao = listaProdutos.at(a).getDescricao();
                                preco = listaProdutos.at(a).getPreco();

                                arquivoSProd << codigo <<endl << nome <<endl << descricao <<endl << preco << endl;
                            }
                            arquivoSProd.close();

                        }
                    }catch(exception& e){
                           // cout << "Erro: " << e.what() <<endl;
                        }
				}else{
                    cout << "Produto nao encontrado!" << endl;
				}
            }
            char v;
            cout << "[V]  -> VOLTAR "; cin >>v;
                if(v=='v'){
                    system("CLS");
                    menuAdmin();
                }
        }

		 void registarVenda(){
            if(listaProdutos.size()== 0)
                cout << "Sem produtos!" << endl;
            else{
                cout <<"nome do produto: " << endl;
                string nome; cin >> nome;
                int quant=0;

                for(int a=0; a<listaProdutos.size(); a++){
                    if(listaProdutos.at(a).getNome() == nome){
                        quant+=1;
                    }
                }
                cout << "Quantidade vendida: "; int qua; cin >> qua;
                if(qua > quant || qua == 0){
                    cout << "Quantidade incorreta!" << endl;
                }else{
                    int posi =0;
                    for(int a = 0 ; a< listaProdutos.size(); a++){
                        if(listaProdutos.at(a).getNome()== nome){
                                posi = a;
                            try{
                                cout << "Nome do produto: " << listaProdutos.at(posi).getNome() << endl;
                                cout << "Tamanho antes " << listaProdutos.size() << endl;
                                listaProdutos.erase(listaProdutos.begin()+posi);
                                posi = 0;
                                cout << "Tamanho depois " << listaProdutos.size() << endl;
                            }catch(exception e){}
                        }else{

                        }
                            qua-=1;
                            if(qua == 0)
                                break;

                    }

                    arquivoSProd.open("Produtos.txt");
                    string codigo;
                    string nome;
                    string descricao;
                    string preco;

                    for(int i = 0; i <listaProdutos.size(); i++){
                        codigo = listaProdutos.at(i).getCodigo();
                        nome = listaProdutos.at(i).getNome();
                        descricao = listaProdutos.at(i).getDescricao();
                        preco = listaProdutos.at(i).getPreco();
                        arquivoSProd << codigo <<endl << nome <<endl << descricao <<endl << preco << endl;
                    }
                    arquivoSProd.close();
                    system("CLS");
                    cout << "Venda registrada!" << endl;
                }
            }
            char v;
            cout << "[V]  -> VOLTAR "; cin >>v;
                if(v=='v'){
                    system("CLS");
                    menuUser();
                }
        }

        void consultarProdutos(){
            string nome; string desc;
            int posi = 0;
            if(listaProdutos.size() == 0)
                cout << "Sem produtos!" << endl;
            else{
                cout <<"Digite o nome: " <<endl;
                 cin >> nome;
                cout <<"Digite a descricao: " << endl;
                 cin >> desc;

                bool existe = false;
                for(int a=0; a<listaProdutos.size(); a++){
                    if((listaProdutos.at(a).getNome() == nome) && (listaProdutos.at(a).getDescricao() == desc)){
                        existe = true;
                        posi = a;
                        break;
                    }
                }
                if(existe == false)
                    cout <<"Produto nao achado!" << endl;
                else{
                    cout << "Cod  Nom  Desc" << endl;
                    cout << listaProdutos.at(posi).getCodigo() <<" " <<listaProdutos.at(posi).getNome() <<" " <<listaProdutos.at(posi).getDescricao() << endl;
                    }
                }

                char v;
                cout << "[V]  -> VOLTAR "; cin >>v;
                    if(v=='v'){
                    system("CLS");
                    menuUser();
                }
            }
        usuarioListarProdutos(){
            if(listaProdutos.size() == 0){
                system("CLS");
				cout << "Nao existem Produtos!" << endl;

			}else{
                cout << "=========================================="<< endl;
                cout << "Codigo    Nome    Descricao    Preco" << endl;
                cout << "=========================================="<< endl;
                cout << "Total Produtos: " << listaProdutos.size() <<endl ;
                for(int a =0; a< listaProdutos.size(); a++){
                    cout <<"[" <<a+1 <<"] " <<listaProdutos.at(a).getCodigo() <<"  " << listaProdutos.at(a).getNome() <<"  " << listaProdutos.at(a).getDescricao() << "  " << listaProdutos.at(a).getPreco()<<endl;
                }
                cout << endl;
                cout << endl;
            }
            char v;
                cout << "[V]  -> VOLTAR "; cin >>v;
                    if(v=='v'){
                    system("CLS");
                    menuUser();
                }

        }


};

int main(){
    Operacoes opera;
    opera.login();
    return 0;
}
