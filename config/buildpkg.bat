@echo off
REM ***** BEGIN LICENSE BLOCK *****
REM Version: MPL 1.1/GPL 2.0/LGPL 2.1
REM
REM The contents of this file are subject to the Mozilla Public License Version
REM 1.1 (the "License"); you may not use this file except in compliance with
REM the License. You may obtain a copy of the License at
REM http://www.mozilla.org/MPL/
REM
REM Software distributed under the License is distributed on an "AS IS" basis,
REM WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
REM for the specific language governing rights and limitations under the
REM License.
REM
REM The Original Code is mozilla.org code.
REM
REM The Initial Developer of the Original Code is
REM Netscape Communications Corporation.
REM Portions created by the Initial Developer are Copyright (C) 1998
REM the Initial Developer. All Rights Reserved.
REM
REM Contributor(s):
REM
REM Alternatively, the contents of this file may be used under the terms of
REM either the GNU General Public License Version 2 or later (the "GPL"), or
REM the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
REM in which case the provisions of the GPL or the LGPL are applicable instead
REM of those above. If you wish to allow use of your version of this file only
REM under the terms of either the GPL or the LGPL, and not to allow others to
REM use your version of this file under the terms of the MPL, indicate your
REM decision by deleting the provisions above and replace them with the notice
REM and other provisions required by the GPL or the LGPL. If you do not delete
REM the provisions above, a recipient may use your version of this file under
REM the terms of any one of the MPL, the GPL or the LGPL.
REM
REM ***** END LICENSE BLOCK *****
@echo on

@echo off
if not exist %2\NUL echo Warning: %2 does not exist! (you may need to check it out)
if not exist %2\NUL exit 1

cd %2

goto NO_CAFE

if "%MOZ_CAFE%"=="" goto NO_CAFE

mkdir %MOZ_SRC%\mozilla\dist\classes\%2
%MOZ_TOOLS%\bin\sj.exe -classpath %MOZ_SRC%\mozilla\dist\classes;%MOZ_SRC%\mozilla\sun-java\classsrc -d %MOZ_SRC%\mozilla\dist\classes *.java 
goto END

:NO_CAFE

perl.exe %MOZ_SRC%\mozilla\config\outofdate.pl -d %MOZ_SRC%\mozilla\dist\classes\%2 -cfg %1 *.java > doit.bat
call doit.bat
del doit.bat

:END

