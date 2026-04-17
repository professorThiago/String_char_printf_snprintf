#include <Arduino.h>
#include <string.h> // strlen, strcpy, strcat, strcmp, strchr
#include <stdlib.h> // atoi

// ======================================================
// EXEMPLOS COM String
// ======================================================

// Criando Strings
String nome = "Thiago";
String curso = "Arduino";
String mensagem = "Ola";

// Concatenando Strings
mensagem = mensagem + ", " + nome + "! Bem-vindo ao curso de " + curso + ".";

// Exibindo o conteúdo
Serial.println(mensagem);  
// Saída esperada:
// Ola, Thiago! Bem-vindo ao curso de Arduino.

// Tamanho da String
int tamanhoMensagem = mensagem.length();
Serial.println(tamanhoMensagem);

// Acessando um caractere em uma posição específica
char primeiraLetra = mensagem.charAt(0);
Serial.println(primeiraLetra); // O

// Também é possível acessar com colchetes
char segundaLetra = mensagem[1];
Serial.println(segundaLetra); // l

// Procurando um texto dentro da String
int posicaoCurso = mensagem.indexOf("curso");
Serial.println(posicaoCurso);

// Extraindo parte da String
String parte = mensagem.substring(5, 11);
Serial.println(parte); 
// Deve mostrar "Thiago"

// Substituindo texto dentro da String
mensagem.replace("Arduino", "C++");
Serial.println(mensagem);
// Agora a mensagem termina com C++

// Convertendo para maiúsculas
mensagem.toUpperCase();
Serial.println(mensagem);

// Convertendo para minúsculas
mensagem.toLowerCase();
Serial.println(mensagem);

// Convertendo texto numérico para inteiro
String textoNumero = "123";
int numero = textoNumero.toInt();
Serial.println(numero + 10); // 133

// Verificando se a String está vazia
String textoVazio = "";
if (textoVazio.length() == 0)
{
  Serial.println("A String esta vazia");
}

// Convertendo String para const char*
// Isso é útil quando alguma biblioteca espera texto no estilo C
const char* textoComoChar = mensagem.c_str();
Serial.println(textoComoChar);


// ======================================================
// EXEMPLOS COM TEXTO ESTILO C: char* e char[]
// ======================================================

// Texto literal
// Use const char* quando o texto nao sera alterado
const char* cidade = "Sao Paulo";
Serial.println(cidade);

// Descobrindo o tamanho do texto
// strlen conta os caracteres antes do '\0'
int tamanhoCidade = strlen(cidade);
Serial.println(tamanhoCidade);

// Comparando textos
const char* cidade1 = "Santos";
const char* cidade2 = "Santos";

if (strcmp(cidade1, cidade2) == 0)
{
  Serial.println("Os textos sao iguais");
}
else
{
  Serial.println("Os textos sao diferentes");
}

// ======================================================
// TEXTO EDITAVEL COM char[]
// ======================================================

// Quando você quer alterar o conteúdo, o ideal é usar um vetor de char
char nomeAluno[20] = "Carlos";
Serial.println(nomeAluno);

// Alterando caracteres individualmente
nomeAluno[0] = 'M';
Serial.println(nomeAluno); // Marlos

// Copiando outro texto para dentro do vetor
// Cuidado: o vetor precisa ter espaço suficiente
strcpy(nomeAluno, "Mariana");
Serial.println(nomeAluno);

// Concatenando texto ao final
char frase[40] = "Ola ";
strcat(frase, "mundo");
Serial.println(frase); // Ola mundo

// Acrescentando mais texto
strcat(frase, " Arduino");
Serial.println(frase); // Ola mundo Arduino

// Tamanho do texto atual
int tamanhoFrase = strlen(frase);
Serial.println(tamanhoFrase);

// Procurando um caractere no texto
char* posicaoLetra = strchr(frase, 'A');

if (posicaoLetra != NULL)
{
  Serial.println("Letra encontrada");
  Serial.println(posicaoLetra);
  // Mostra a partir da letra encontrada
  // Exemplo: Arduino
}
else
{
  Serial.println("Letra nao encontrada");
}

// Convertendo texto numérico para inteiro
char idadeTexto[] = "45";
int idade = atoi(idadeTexto);
Serial.println(idade);

// ======================================================
// USANDO char* APONTANDO PARA UM VETOR DE char
// ======================================================

// Aqui temos um vetor editável
char textoEditavel[30] = "robotica";

// Um ponteiro char* pode apontar para esse vetor
char* ponteiroTexto = textoEditavel;

Serial.println(ponteiroTexto);

// Alterando o conteúdo pelo ponteiro
ponteiroTexto[0] = 'R';
Serial.println(ponteiroTexto); // Robotica

// Copiando novo valor para o mesmo espaço de memória
strcpy(ponteiroTexto, "iot");
Serial.println(ponteiroTexto);

// ======================================================
// CUIDADO IMPORTANTE COM char*
// ======================================================

// Isto aqui deve ser evitado:
char* textoErrado = (char*)"Teste";

// O problema é que "Teste" é um texto literal.
// Em C++ moderno, texto literal deve ser tratado como const char*.
// O correto é:
const char* textoCorreto = "Teste";
Serial.println(textoCorreto);

// Se quiser alterar, use vetor:
char textoCerto[] = "Teste";
textoCerto[0] = 'V';
Serial.println(textoCerto); // Veste


// ======================================================
// RESUMO PRÁTICO
// ======================================================

// String é mais fácil de usar
String produto = "Sensor";
produto += " MQ-135";
Serial.println(produto);

// char[] dá mais controle de memória
char produto2[20] = "Sensor";
strcat(produto2, " DHT11");
Serial.println(produto2);



//!==========================================================================================


// Este exemplo considera que a Serial já foi iniciada antes com Serial.begin()

// ======================================================
// EXEMPLO 1: TEXTO SIMPLES
// ======================================================

Serial.printf("Ola, mundo!\n");

// \n significa quebra de linha
Serial.printf("Linha 1\n");
Serial.printf("Linha 2\n");


// ======================================================
// EXEMPLO 2: IMPRIMINDO VALORES INTEIROS
// ======================================================

int idade = 35;
int ano = 2026;

Serial.printf("Idade: %d\n", idade);
Serial.printf("Ano atual: %d\n", ano);

// %d representa número inteiro decimal


// ======================================================
// EXEMPLO 3: IMPRIMINDO MAIS DE UMA VARIAVEL
// ======================================================

int nota1 = 8;
int nota2 = 9;
int media = (nota1 + nota2) / 2;

Serial.printf("Nota 1: %d | Nota 2: %d | Media: %d\n", nota1, nota2, media);

// A ordem das variáveis deve seguir a ordem dos marcadores %d


// ======================================================
// EXEMPLO 4: IMPRIMINDO TEXTO COM %s
// ======================================================

const char* nome = "Thiago";
const char* curso = "Arduino";

Serial.printf("Professor: %s\n", nome);
Serial.printf("Curso: %s\n", curso);
Serial.printf("%s esta ministrando o curso de %s\n", nome, curso);

// %s representa texto no formato const char* ou char*


// ======================================================
// EXEMPLO 5: USANDO String COM printf
// ======================================================

String cidade = "Sao Caetano do Sul";
String disciplina = "Programacao em C++";

// String nao deve ser passada diretamente para %s
// O correto é usar .c_str()

Serial.printf("Cidade: %s\n", cidade.c_str());
Serial.printf("Disciplina: %s\n", disciplina.c_str());

// Exemplo misturando String com inteiro
int alunos = 25;
Serial.printf("Turma de %s com %d alunos\n", disciplina.c_str(), alunos);


// ======================================================
// EXEMPLO 6: IMPRIMINDO CARACTERE COM %c
// ======================================================

char letra = 'A';
char simbolo = '#';

Serial.printf("Letra: %c\n", letra);
Serial.printf("Simbolo: %c\n", simbolo);

// %c representa um único caractere


// ======================================================
// EXEMPLO 7: NÚMEROS FLOAT
// ======================================================

float temperatura = 23.75;
float umidade = 68.4;

// %.2f significa:
// %f  -> número decimal
// .2  -> mostrar 2 casas decimais

Serial.printf("Temperatura: %.2f C\n", temperatura);
Serial.printf("Umidade: %.1f %%\n", umidade);

// %% é usado para imprimir o caractere %


// ======================================================
// EXEMPLO 8: HEXADECIMAL
// ======================================================

int valor = 255;

Serial.printf("Decimal: %d\n", valor);
Serial.printf("Hexadecimal minusculo: %x\n", valor);
Serial.printf("Hexadecimal maiusculo: %X\n", valor);

// %x e %X mostram o número em hexadecimal


// ======================================================
// EXEMPLO 9: FORMATANDO LARGURA
// ======================================================

int numero = 7;

// %5d reserva 5 espaços
Serial.printf("Numero com largura 5: '%5d'\n", numero);

// %05d completa com zero à esquerda
Serial.printf("Numero com zeros à esquerda: '%05d'\n", numero);

// Muito usado para horário, datas e identificadores
int hora = 8;
int minuto = 3;
int segundo = 5;

Serial.printf("Horario: %02d:%02d:%02d\n", hora, minuto, segundo);


// ======================================================
// EXEMPLO 10: MISTURANDO TIPOS
// ======================================================

const char* sensor = "DHT11";
float temperatura2 = 24.6;
float umidade2 = 61.2;
int leitura = 15;

Serial.printf("Sensor: %s | Leitura: %d | Temp: %.1f C | Umidade: %.1f %%\n",
              sensor, leitura, temperatura2, umidade2);


// ======================================================
// EXEMPLO 11: USANDO char[]
// ======================================================

char nomeAluno[] = "Carlos";
int faltas = 2;

Serial.printf("Aluno: %s | Faltas: %d\n", nomeAluno, faltas);

// char[] também funciona com %s


// ======================================================
// EXEMPLO 12: TEXTO LITERAL DIRETO
// ======================================================

Serial.printf("ESP32 conectado ao WiFi\n");
Serial.printf("IP: %s\n", "192.168.0.10");


// ======================================================
// EXEMPLO 13: IMPRIMINDO BOOLEAN
// ======================================================

bool conectado = true;

// printf nao tem um especificador especial para bool
// Então normalmente usamos um texto
Serial.printf("WiFi conectado? %s\n", conectado ? "Sim" : "Nao");


// ======================================================
// EXEMPLO 14: USANDO snprintf PARA MONTAR TEXTO EM BUFFER
// ======================================================

char mensagem[100];
int temperaturaSala = 26;
int umidadeSala = 55;

snprintf(mensagem, sizeof(mensagem),
         "Sala monitorada | Temp: %d C | Umidade: %d %%", 
         temperaturaSala, umidadeSala);

Serial.println(mensagem);

// snprintf monta o texto dentro de um vetor de char
// Isso é muito útil quando depois você quer:
// - enviar por MQTT
// - salvar em variável
// - mandar para display
// - reutilizar a mensagem


// ======================================================
// EXEMPLO 15: USANDO String + snprintf
// ======================================================

String nomeDispositivo = "ESP32-Sala-01";
char buffer[120];

snprintf(buffer, sizeof(buffer),
         "Dispositivo: %s | Status: %s",
         nomeDispositivo.c_str(),
         "Online");

Serial.println(buffer);


// ======================================================
// EXEMPLO 16: ERRO COMUM
// ======================================================

String materia = "IoT";

// Errado:
// Serial.printf("Materia: %s\n", materia);

// Certo:
Serial.printf("Materia: %s\n", materia.c_str());


// ======================================================
// EXEMPLO 17: OUTRO ERRO COMUM
// ======================================================

int valorSensor = 123;

// Errado: usar %s para inteiro
// Serial.printf("Valor: %s\n", valorSensor);

// Certo:
Serial.printf("Valor: %d\n", valorSensor);