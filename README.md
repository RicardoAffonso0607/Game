<img src="https://upload.wikimedia.org/wikipedia/commons/8/86/GPL_v3_Blue_Badge.svg"/>    <img src="https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white"/>    <img src="https://www.sfml-dev.org/images/logo.png" height="20" />

# Jogo: Age of Warriors++

Trabalho da disciplina Técnicas de Programação.

## Autores

* Ricardo Affonso
* Lucas Yukio Fukuda Matsumoto

## Ferramentas e Requisitos

* SO Windows 32 ou 64 bits
* SFML 2.5.1
* Microsoft Visual Studio 2022 (v143)
* Ferramentas Microsoft Visual C++
* Windows Driver Kit Windows 11 22H2
* ISO C++ 20
* ISO C 17 (2018)

### Configurações do Projeto AgeOfWarriors.vcxproj no Visual Studio 2022

Selecionar

- Configuração: Debug
- Plataforma: Todas as Plataformas


Propriedades de Configuração -> C/C++ -> Vinculador -> Entrada -> Dependências Adicionais -> sfml-graphics-d.lib;sfml-window-d.lib;sfml-audio-d.lib;sfml-network-d.lib;sfml-system-d.lib;%(AdditionalDependencies)

------------------

Selecionar

* Configuração: Release
* Plataforma: Todas as Plataformas

Propriedades de Configuração -> C/C++ -> Vinculador -> Entrada -> Dependências Adicionais -> sfml-graphics.lib;sfml-window.lib;sfml-audio.lib;sfml-network.lib;sfml-system.lib;%(AdditionalDependencies)

------------------

Selecionar

- Configuração: Todas as Configurações
- Plataforma: Todas as Plataformas

Propriedades de Configuração -> Geral -> Propriedades Gerais -> Visual Studio 2022 (v143)

Propriedades de Configuração -> Geral -> Propriedades Gerais -> Padrão de Linguagem C++ -> Padrão ISO C++ 20 (/std:c++20)

Propriedades de Configuração -> Geral -> Propriedades Gerais -> Padrão de Linguagem C -> Padrão ISO C17 (2018) (/std:c17)

Propriedades de Configuração -> Diretórios VC++ -> Diretórios de Inclusão -> "$(SolutionDir)\Game\inc;$(IncludePath)"

Propriedades de Configuração -> Diretórios VC++ -> Diretórios de Origem -> "$(SolutionDir)\Game\src;$(SourcePath)"

Propriedades de Configuração -> C/C++ -> Cabeçalhos Pré-compilados -> Cabeçalho Pré-compilado -> Usar (/Yu)

Propriedades de Configuração -> C/C++ -> Cabeçalhos Pré-compilados -> Arquivo de Cabeçalho Pré-compilado -> pch.h

------------------

Selecionar

* Configuração: Todas as Configurações
* Plataforma: Win32

Propriedades de Configuração -> Depuração -> Ambiente -> PATH=%PATH%;$(SolutionDir)\SFML-2.5.1x86\bin;$(LocalDebuggerEnvironment)

Propriedades de Configuração -> C/C++ -> Geral -> Diretórios de Inclusão Adicionais -> $(SolutionDir)\SFML-2.5.1x86\include;%(AdditionalIncludeDirectories)

Propriedades de Configuração -> Vinculador -> Geral -> Diretórios de Biblioteca Adicionais -> $(SolutionDir)\SFML-2.5.1x86\lib;%(AdditionalLibraryDirectories)

------------------

Selecionar

- Configuração: Todas as Configurações
- Plataforma: x64

Propriedades de Configuração -> Depuração -> Ambiente -> PATH=%PATH%;$(SolutionDir)\SFML-2.5.1x64\bin;$(LocalDebuggerEnvironment)

Propriedades de Configuração -> C/C++ -> Geral -> Diretórios de Inclusão Adicionais -> $(SolutionDir)\SFML-2.5.1x64\include;%(AdditionalIncludeDirectories)

Propriedades de Configuração -> Vinculador -> Geral -> Diretórios de Biblioteca Adicionais -> $(SolutionDir)\SFML-2.5.1x64\lib;%(AdditionalLibraryDirectories)

------------------

Botão direito no pch.cpp -> Propriedades

Selecionar

* Configuração: Todas as Configurações
* Plataforma: Todas as Plataformas

Propriedades de Configuração -> C/C++ -> Cabeçalhos Pré-compilados -> Cabeçalho Pré-compilado -> Criar (/Yc)

------------------
