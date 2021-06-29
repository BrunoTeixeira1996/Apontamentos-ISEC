function varargout = DerivacaoNumerica(varargin)
% DERIVACAONUMERICA M-file for DerivacaoNumerica.fig
%      DERIVACAONUMERICA, by itself, creates a new DERIVACAONUMERICA or raises the existing
%      singleton*.
%
%      H = DERIVACAONUMERICA returns the handle to a new DERIVACAONUMERICA or the handle to
%      the existing singleton*.
%
%      DERIVACAONUMERICA('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in DERIVACAONUMERICA.M with the given input arguments.
%
%      DERIVACAONUMERICA('Property','Value',...) creates a new DERIVACAONUMERICA or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before DerivacaoNumerica_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to DerivacaoNumerica_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help DerivacaoNumerica

% Last Modified by GUIDE v2.5 21-May-2020 23:16:24

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @DerivacaoNumerica_OpeningFcn, ...
                   'gui_OutputFcn',  @DerivacaoNumerica_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before DerivacaoNumerica is made visible.
function DerivacaoNumerica_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to DerivacaoNumerica (see VARARGIN)

% Choose default command line output for DerivacaoNumerica
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes DerivacaoNumerica wait for user response (see UIRESUME)
% uiwait(handles.figureDerivacaoNumerica);
MyAtualizar(handles);

% --- Executes when user attempts to close figureDerivacaoNumerica.
function figureDerivacaoNumerica_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figureDerivacaoNumerica (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure
%delete(hObject);
set(hObject,'Visible','Off');

% --- Outputs from this function are returned to the command line.
function varargout = DerivacaoNumerica_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pbAtualiza.
function pbAtualiza_Callback(hObject, eventdata, handles)
% hObject    handle to pbAtualiza (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
MyAtualizar(handles);


function eA_Callback(hObject, eventdata, handles)
% hObject    handle to eA (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eA as text
%        str2double(get(hObject,'String')) returns contents of eA as a double


% --- Executes during object creation, after setting all properties.
function eA_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eA (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function eH_Callback(hObject, eventdata, handles)
% hObject    handle to eH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eH as text
%        str2double(get(hObject,'String')) returns contents of eH as a double


% --- Executes during object creation, after setting all properties.
function eH_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eH (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function eB_Callback(hObject, eventdata, handles)
% hObject    handle to eB (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eB as text
%        str2double(get(hObject,'String')) returns contents of eB as a double


% --- Executes during object creation, after setting all properties.
function eB_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eB (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function MyAtualizar(handles)

syms x;
strF=get(handles.eY,'String');
f=@(x) eval(vectorize(char(strF)));
df=diff(f(x));

a=str2num(get(handles.eA,'String'));
h=str2num(get(handles.eH,'String'));
b=str2num(get(handles.eB,'String'));

checkAReal=MException('MATLAB:MyAtualizar:badAReal','Introduza um número real (a)');
checkBReal=MException('MATLAB:MyAtualizar:badBReal','Introduza um número real (b)');
checkB_A=MException('MATLAB:MyAtualizar:badBA','(a) tem de ser inferior a (b)');
checkH=MException('MATLAB:MyAtualizar:badHInteiro','o (h) tem de ser positivo');
TestF=MException('MATLAB:MyAtualizar:badTestF','Input inválido');

try
    try 
        testfunc = f(sym('y'));
        set(handles.eY,'BackgroundColor','white');
        
    catch
        set(handles.eY,'BackgroundColor','r');
        throw(TestF)
        
    end

	if ~(isscalar(a)&&isreal(a))
		set(handles.eA,'BackgroundColor','red');
		throw(checkAReal);
	else
		set(handles.eA,'BackgroundColor','white');
		
		if ~(isscalar(b)&&isreal(b))
			set(handles.eB,'BackgroundColor','red');
			throw(checkBReal);
		else
			set(handles.eB,'BackgroundColor','white');
			
			if ~(b>a)
				set(handles.eA,'BackgroundColor','red');
				set(handles.eB,'BackgroundColor','red');
				throw(checkB_A);
			else
				set(handles.eA,'BackgroundColor','white');
				set(handles.eB,'BackgroundColor','white');
				
				if ~(isscalar(h) && h > 0)
					set(handles.eH,'BackgroundColor', 'red');
					throw(checkH);
 				else
					set(handles.eH,'BackgroundColor','white');
				end
			end
		end
	end

	escolhabg=get(handles.bgFormulasDNumerica,'SelectedObject');
    
	escolhafb=find([handles.rbDFP2...
        handles.rbDFR2...
        handles.rbDFC3...
        handles.rbDFP3...
        handles.rbDFR3...
        handles.rbDFD2]==escolhabg);
    
	switch escolhafb
		case 1
			[x,y,dydx]=DI_DFProgressivas_2(f,a,b,h);
			legenda='rbDFP2';
		case 2
			[x,y,dydx]=DI_DFRegressivas_2(f,a,b,h);
			legenda='rbDFR2';
		case 3
			[x,y,dydx]=DI_DFCentradas_3(f,a,b,h);
			legenda='rbDFC3';

		case 4
			[x,y,dydx]=DI_DFProgressivas_3(f,a,b,h);
			legenda='rbDFP3';
		case 5
			[x,y,dydx]=DI_DFRegressivas_3(f,a,b,h);
			legenda='rbDFR3';
		case 6
			[x,y,dydx]=DI_DFDerivada_2(f,a,b,h);
			legenda='rbDFD2';
			df=diff(df);
	end

	dydxExata=eval(df);
	
	if(length(dydxExata) == 1)
		for i=1:length(dydx)
			dydxExata(i)=eval(df);
		end
	end
	
	erroDF=abs(dydxExata-dydx);
	plot(x,y,'b--');
	hold on
	plot(x,dydx,'-r');
	plot(x,dydxExata,'-k');
	hold off;
	legend(char(strF), legenda, char(df));
	set(handles.uitabela,'ColumnName',[{'x'},{'y'},{legenda},{'dExata'},{'Erro'}]);
	set(handles.uitabela,'Data',num2cell([x.',y.',dydx.',dydxExata.',erroDF.']));
	clc;
	
catch Me
	errordlg(Me.message,'ERRO','modal');
	clc;
end


% --- Executes on button press in rbDFD2.
function rbDFD2_Callback(hObject, eventdata, handles)
% hObject    handle to rbDFD2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rbDFD2




% --- Executes during object creation, after setting all properties.
function pbAtualiza_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pbAtualiza (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called



function eY_Callback(hObject, eventdata, handles)
% hObject    handle to eY (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eY as text
%        str2double(get(hObject,'String')) returns contents of eY as a double


% --- Executes during object creation, after setting all properties.
function eY_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eY (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
