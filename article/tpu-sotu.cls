%
% tpu-sotu.cls
%
% sotsuron.sty 20-Jan-92 by Yasuharu DEN
% revised      11-Jan-94 by Y. USUI                             
% revised       6-Jan-99 by Toru Nakazawa(In Marsh)

\NeedsTeXFormat{pLaTeX2e}
\ProvidesClass{tpu-sotu}[1999/01/06 v1.0 Standard pLaTeX class]

\InputIfFileExists{tpu-sotu.cfg}%
  {\ClassInfo{tpu-sotu}{Using local configuration file}}%
  {\ClassInfo{tpu-sotu}{No local configuration file}}
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{tpu-sotu}}
\newcommand{\@tpuptsize}{}
\DeclareOption{10pt}{\renewcommand{\@tpuptsize}{10pt}
		     \def\@tputextheight{45.5}}
\DeclareOption{11pt}{\renewcommand{\@tpuptsize}{11pt}
		     \def\@tputextheight{44}}
\DeclareOption{12pt}{\renewcommand{\@tpuptsize}{12pt}
		     \def\@tputextheight{41.5}}
\DeclareOption{draft}{\setlength\overfullrule{5pt}}
\DeclareOption{final}{\setlength\overfullrule{0pt}}
\ExecuteOptions{12pt,final}
\ProcessOptions
\LoadClass[a4j,\@tpuptsize]{jreport}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Chapter の前後のスペースを小さくする
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\def\@makechapterhead#1{\hbox{}%
  \vskip\Cvs
  {\parindent\z@
   \raggedright
   \reset@font\huge\bfseries
   \ifnum \c@secnumdepth >\m@ne
     \setlength\@tempdima{\linewidth}%
     \setbox\z@\hbox{\@chapapp\thechapter\@chappos\hskip1zw}%
     \addtolength\@tempdima{-\wd\z@}%
     \unhbox\z@\nobreak
     \vtop{\hsize\@tempdima#1}%
   \fi}\vskip1.5\Cvs}
\def\@makeschapterhead#1{\hbox{}%
  \vskip\Cvs
  {\parindent\z@
   \raggedright
   \reset@font\huge\bfseries
   \setlength\@tempdima{\linewidth}%
   \vtop{\hsize\@tempdima#1}}\vskip1.5\Cvs}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% \maketitle parameters.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\newcommand{\professor}{\renewcommand{\@professor}}
\newcommand{\@professor}{\ClassError{tpu-sotu}
   {No \protect\professor~given}\@eha}

\newcommand{\eauthor}{\renewcommand{\@eauthor}}
\newcommand{\@eauthor}{\ClassError{tpu-sotu}
   {No \protect\eauthor~given}\@eha}

\newcommand{\etitle}{\renewcommand{\@etitle}}
\newcommand{\@etitle}{\ClassError{tpu-sotu}
   {No \protect\etitle~given}\@eha}

\newcommand{\department}{\renewcommand{\@department}}
\newcommand{\@department}{\ClassError{tpu-sotu}
   {No \protect\department~given}\@eha}

\newcommand{\nyugaku}{\renewcommand{\@nyugaku}}
\newcommand{\@nyugaku}{\ClassError{tpu-sotu}
   {No \protect\nyugaku~given}\@eha}

\newcommand{\gakusekibangou}{\renewcommand{\@gakusekibangou}}
\newcommand{\@gakusekibangou}{\ClassError{tpu-sotu}
   {No \protect\gakusekibangou~given}\@eha}

\def\@maintitle{卒 \ 業 \  論 \  文}
\def\@course{富山県立大学工学部}

\def\offset{0.5}

\def\maketitle{
 \begin{titlepage}
  \let\footnoterule\relax \setcounter{page}{0}
  \thispagestyle{empty}
  \begin{figure}\center
  \unitlength = 1cm
  \begin{picture}(1,1)(\offset,0)
  \put(1.0,9){\makebox(0,0)[b]{\makebox[8cm]{\LARGE \@maintitle}}}%
 %\put(-7.0,6.5){\makebox(0,0)[l]{\makebox[2.3cm]{\large 題\hfil \hfil \hfil\hfil 目}}} 
  \put(1.0,6.5){\makebox(0,0){\parbox[b]{12.7cm}{\center \Large \@title}}}
 %\put(-7.0,6.85){\makebox(0,0)[l]{\makebox[3.3cm]{ \large English Title}}}
  \put(1.0,5.0){\makebox(0,0){\parbox[b]{15.7cm}{\center \large \@etitle}}}
  \put(-2.65,2.45){\makebox(0,0)[l]{\makebox[2.3cm]{\large 指\hfil 導\hfil 
教\hfil 員}}}%
  \put(2.5,2.7){\makebox(0,0){\parbox[b]{8cm}{\center \Large \@professor}}}
        
  \put(-2.85,-5.0){\makebox(0,0)[lt]{\large \@course\ \@department}}%
 %\put(-5.5,-8.5){\makebox(0,0)[l]{\large \@nyugaku 入学}}%
  \put(1,-7.0){\makebox(0,0)[t]{\makebox[2cm]{学\hfil 籍\hfil 番\hfil 号}%
\ :\ \ \large\@gakusekibangou}}
  \put(-0.05,-8.5){\makebox(0,0)[r]{\makebox[1.5cm]{\large 氏\hfil 名}}}%
  \put(2.3,-8.7){\makebox(0,0)[b]{\LARGE \@author}}%
  \put(1.05,-10){\makebox(0,0)[t]{\makebox[2cm]{提\hfil 出\hfil 年\hfil 月}%
\large\ \ \@date}}%
  \end{picture}
  \end{figure}
  \setcounter{footnote}{0}
  \let\thanks\relax
  \def\@thanks{}\def\@author{}\def\@title{}%
  \def\@professor{}\def\@course{}\def\department{}%
  \let\maketitle\relax
 \end{titlepage}%
}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 謝辞を目次に載せる
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\def\acknowledgements{%
  \c@secnumdepth = \m@ne
  \chapter*{\ackname\@mkboth{\ackname}{\ackname}\thispagestyle{plain}
  \addcontentsline{toc}{chapter}{\ackname}}
  \addtocontents{lof}{\protect\addvspace{10\p@}}%
  \addtocontents{lot}{\protect\addvspace{10\p@}}%
  \hspace{\parindent}%
}
\def\ackname{謝 辞}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 参考文献を目次に出してラベルを丸括弧でくくる
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\def\bibname{参 考 文 献}
\def\@biblabel#1{(#1)}
\def\@cite#1#2{{$^{\mbox{\scriptsize $#1$}}$%
    \if@tempswa , #2\fi}$^{\mbox{\scriptsize $)$}}$ }
\renewenvironment{thebibliography}[1]
{\chapter*{\bibname\@mkboth{\bibname}{\bibname}}%
   \list{\@biblabel{\@arabic\c@enumiv}}%
	{\settowidth\labelwidth{\@biblabel{#1}}%
	 \leftmargin\labelwidth
	 \advance\leftmargin\labelsep
	 \@openbib@code
	 \usecounter{enumiv}%
	 \let\p@enumiv\@empty
	 \renewcommand\theenumiv{\@arabic\c@enumiv}}%
   \sloppy
   \clubpenalty4000
   \@clubpenalty\clubpenalty
   \widowpenalty4000%
   \sfcode`\.\@m
   \addcontentsline{toc}{chapter}{\protect\numberline{\bibname}}
   }
  {\def\@noitemerr
    {\@latex@warning{Empty `thebibliography' environment}}%
   \endlist}
\endinput
