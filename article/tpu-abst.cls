%
% tpu-abst.cls
%
% この class file は，plnews.cls を参考にしています．
%                   Written by Toru Nakazawa(In Marsh) 1998/2/4
%
% 2013.1.29: by Ms.K
% 変更： 研究室名と学籍番号＆氏名を右揃えに
% 変更： textheight=257mm固定
% 2010.1.24: by Ms.K
% 変更： 情報システム工学科用に変更
%
% 2005.2.7: by Ms.K
% 変更： 研究室名と学籍番号＆氏名を左揃えに
% 変更： labname=10 計算機センター → ソフトウェア工学
% 2006.2.14: by Ms.K
% 変更： sectionタイトル左寄せ
%
\NeedsTeXFormat{pLaTeX2e}
\ProvidesClass{tpu-abst}[1998/02/05 v1.0a Standard pLaTeX class]

\InputIfFileExists{tpu-abst.cfg}%
  {\ClassInfo{tpu-abst}{Using local configuration file}}%
  {\ClassInfo{tpu-abst}{No local configuration file}}
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{tpu-abst}}
\newcommand{\@tpuptsize}{}
\DeclareOption{10pt}{\renewcommand{\@tpuptsize}{10pt}
		     \def\@tputextheight{45.5}}
\DeclareOption{11pt}{\renewcommand{\@tpuptsize}{11pt}
		     \def\@tputextheight{44}}
\DeclareOption{12pt}{\renewcommand{\@tpuptsize}{12pt}
		     \def\@tputextheight{41.5}}
\DeclareOption{draft}{\setlength\overfullrule{5pt}}
\DeclareOption{final}{\setlength\overfullrule{0pt}}
\ExecuteOptions{10pt,final}
\ProcessOptions
\LoadClass[twocolumn,a4j,\@tpuptsize]{jarticle}
\pagestyle{empty}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% \maketitle parameters.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\newcommand{\@titlefont}{\normalfont\huge\bfseries\raggedright}

\newcommand{\kouzanum}{\renewcommand{\@kouzanum}}
\newcommand{\@kouzanum}{\ClassError{tpu-abst}
   {No \protect\kouzanum~given}\@eha}

\newcommand{\kouzaname}{\renewcommand{\@kouzaname}}
\newcommand{\@kouzaname}{\ClassError{tpu-abst}
   {No \protect\kouzaname~given}\@eha}

\newcommand{\happyou}{\renewcommand{\@happyou}}
\newcommand{\@happyou}{\ClassError{tpu-abst}
   {No \protect\happyou~given}\@eha}

\newcommand{\gakuban}{\renewcommand{\@gakuban}}
\newcommand{\@gakuban}{\ClassError{tpu-abst}
   {No \protect\gakuban~given}\@eha}

% 2010.1.24 -- revised
%\renewcommand{\maketitle}{%
%   \twocolumn[%
%      {\@titlefont\@kouzanum --\@happyou\hskip1zw\parbox[t][3\Cvs]{20zw}{%
%         \@title}}%
%	 \par\vskip\baselineskip%
%	 \raggedleft{\normalfont\large\parbox{11zw}{%\centering%
%	 \labname{\@kouzanum}\par%
%		  \@gakuban \@author}}%
%	 \vskip\baselineskip%
%   ]}%
\renewcommand{\maketitle}{%
   \twocolumn[%
      {\@titlefont\@kouzanum --\@happyou\hskip1zw\parbox[t][3\Cvs]{20zw}{%
         \@title}}%
	 \par\vskip\baselineskip%
	 \raggedleft{\normalfont\large\parbox{11zw}{%\centering%
	     \hfill \labname \par%
	     \hfill \@gakuban \@author
	 }}%
	 \vskip\baselineskip%
   ]}%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Sectioning
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\renewcommand{\section}{\@startsection{section}{1}{\z@}%
   {.3\Cvs \@plus.5\Cdp \@minus.2\Cdp}%
   {.3\Cvs \@plus.3\Cdp}%
%   {\hskip-.5zw\reset@font\large\bfseries\underline}} 2006.2.14 revised
   {\hskip-1zw\reset@font\large\bfseries\underline}}
\renewcommand{\thesection}{\arabic{section}.\hspace{-1zw}}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Page Layout
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\setlength\oddsidemargin{-0.4mm}
\setlength\topmargin{-17.0mm}
%\setlength\textheight{\@tputextheight\Cvs}
\setlength\textheight{257mm}
\setlength\footskip{0mm}
\setlength\textwidth{170mm}
\setlength\abovecaptionskip{5\p@}
\setlength\belowcaptionskip{-10\p@}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% misc.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%\def\labname#1{%
%    \ifcase#1 ななしの\or 電磁解析\or 電子回路\or 制御システム工学\or 計
%    算機工学\or 情報工学\or 通信工学\or 電磁波工学\or 機能材料工学\or デ
%    バイス工学\or ソフトウェア工学\or 視覚情報処理\or 固体物性\or 音声言語
%    工学\fi\kouzatitle}
\def\kouzatitle{研究室}
\def\labname{\@kouzaname\kouzatitle}
\endinput
