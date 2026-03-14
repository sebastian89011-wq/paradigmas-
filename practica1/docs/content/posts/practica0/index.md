+++
date = '2026-03-13T20:58:26-07:00'
draft = false
title = 'Practica0'
+++

# Reporte – Markdown, Git, GitHub, Hugo y GitHub Actions

**Autor:**  
**Materia:**  
**Fecha:**  

## Primera sesión

### Sintaxis y uso de Markdown

#### ¿Qué es Markdown?
Markdown es un lenguaje de marcado ligero que permite dar formato a texto plano de manera sencilla. Se utiliza principalmente para:

- Documentación técnica
- Archivos `README` en repositorios
- Blogs y páginas estáticas
- Notas y reportes

Su principal ventaja es que es fácil de leer y escribir, incluso sin procesarlo.

#### ¿Cómo se utiliza?
Markdown se escribe en archivos con extensión `.md`.

Ejemplo:

```md
# Título
## Subtítulo
Texto en **negritas** y *cursiva*.
```

Estos archivos pueden visualizarse directamente en:

- Visual Studio Code (vista previa)
- GitHub
- Generadores de sitios estáticos

### Sintaxis básica de Markdown

#### Encabezados
```md
# Título 1
## Título 2
### Título 3
```

#### Negritas y cursivas
```md
**Negritas**
*Cursiva*
```

#### Listas
Lista no ordenada:

```md
- Elemento 1
- Elemento 2
```

Lista ordenada:

```md
1. Elemento 1
2. Elemento 2
```

#### Enlaces
```md
[Texto del enlace](https://ejemplo.com)
```

#### Imágenes
```md
![Texto alternativo](imagen.png)
```

#### Código
Código en línea:

```md
`codigo`
```

Bloque de código:

```c
printf("Hola mundo");
```

## Segunda sesión

### Uso de Git y GitHub

#### ¿Qué es Git?
Git es un sistema de control de versiones distribuido. Permite:

- Registrar cambios en archivos
- Trabajar en equipo
- Volver a versiones anteriores
- Gestionar proyectos de software

#### ¿Qué es GitHub?
GitHub es una plataforma en la nube que aloja repositorios Git. Permite:

- Guardar proyectos en línea
- Colaborar con otras personas
- Publicar código
- Automatizar procesos

### Comandos esenciales de Git

Inicializar repositorio:

```bash
git init
```

Ver estado:

```bash
git status
```

Agregar archivos:

```bash
git add .
```

Crear commit:

```bash
git commit -m "Mensaje del commit"
```

Conectar con GitHub:

```bash
git remote add origin https://github.com/usuario/repositorio.git
```

Subir cambios:

```bash
git push -u origin main
```

### ¿Cómo crear un repositorio en GitHub?

1. Iniciar sesión en GitHub.
2. Hacer clic en **New repository**.
3. Asignar nombre al repositorio.
4. Elegir público o privado.
5. Crear repositorio.
6. Conectar repositorio local usando `git remote add origin`.
7. Subir archivos con `git push`.

## Tercera sesión

### Markdown + Git + Hugo + GitHub Actions

#### ¿Qué es Hugo?
Hugo es un generador de sitios estáticos. Convierte archivos Markdown en páginas web HTML listas para publicarse.

Ventajas:

- Muy rápido
- No requiere base de datos
- Ideal para blogs y portafolios

#### ¿Qué es GitHub Actions?
GitHub Actions es una herramienta de automatización integrada en GitHub. Permite:

- Ejecutar procesos automáticamente
- Compilar proyectos
- Publicar sitios en GitHub Pages

### ¿Cómo crear un sitio estático en Hugo?

Instalar Hugo.

Crear nuevo sitio:

```bash
hugo new site mi-sitio
```

Entrar al directorio:

```bash
cd mi-sitio
```

Agregar un tema.

Crear contenido:

```bash
hugo new posts/primer-post.md
```

Probar en local:

```bash
hugo server
```

### Subir el sitio a GitHub

Inicializar repositorio:

```bash
git init
```

Agregar archivos:

```bash
git add .
```

Crear commit:

```bash
git commit -m "Primer versión del sitio"
```

Conectar con GitHub.

Subir con `git push`.

### Configurar GitHub Actions para GitHub Pages

1. Ir a la sección **Actions** del repositorio.
2. Crear nuevo workflow.
3. Configurar archivo YAML para:
   - Instalar Hugo
   - Construir el sitio
   - Publicar en GitHub Pages
4. Activar GitHub Pages desde:
   - **Settings → Pages**
   - Seleccionar rama generada por Actions.




https://github.com/sebastian89011-wq/mi-sitio


