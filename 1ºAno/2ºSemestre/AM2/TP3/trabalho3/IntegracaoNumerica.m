function varargout = IntegracaoNumerica(varargin)
% INTEGRACAONUMERICA MATLAB code for IntegracaoNumerica.fig
%      INTEGRACAONUMERICA, by itself, creates a new INTEGRACAONUMERICA or raises the existing
%      singleton*.
%
%      H = INTEGRACAONUMERICA returns the handle to a new INTEGRACAONUMERICA or the handle to
%      the existing singleton*.
%
%      INTEGRACAONUMERICA('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in INTEGRACAONUMERICA.M with the given input arguments.
%
%      INTEGRACAONUMERICA('Property','Value',...) creates a new INTEGRACAONUMERICA or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before IntegracaoNumerica_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to IntegracaoNumerica_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help IntegracaoNumerica

% Last Modified by GUIDE v2.5 04-Jun-2020 23:17:18

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @IntegracaoNumerica_OpeningFcn, ...
                   'gui_OutputFcn',  @IntegracaoNumerica_OutputFcn, ...
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


% --- Executes just before IntegracaoNumerica is made visible.
function IntegracaoNumerica_OpeningFcn(hObject, eventdata, handles, varargin)

% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to IntegracaoNumerica (see VARARGIN)

% Choose default command line output for IntegracaoNumerica
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes IntegracaoNumerica wait for user response (see UIRESUME)
% uiwait(handles.figure1);
MyAtualizar(handles);

% --- Outputs from this function are returned to the command line.
function varargout = IntegracaoNumerica_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function eF_Callback(hObject, eventdata, handles)
% hObject    handle to eF (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eF as text
%        str2double(get(hObject,'String')) returns contents of eF as a double


% --- Executes during object creation, after setting all properties.
function eF_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eF (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



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



function eN_Callback(hObject, eventdata, handles)
% hObject    handle to eN (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eN as text
%        str2double(get(hObject,'String')) returns contents of eN as a double


% --- Executes during object creation, after setting all properties.
function eN_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eN (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pbCalcula.
function pbCalcula_Callback(hObject, eventdata, handles)
% hObject    handle to pbCalcula (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
MyAtualizar(handles);

function MyAtualizar(handles)
syms x;
strF=get(handles.eF,'String');
f=@(x) eval(vectorize(strF));
df=diff(f(x));
dfdx=@(x)eval(vectorize(char(df)));
a=str2num(get(handles.eA,'String'));
b=str2num(get(handles.eB,'String'));
n=str2num(get(handles.eN,'String'));

escolhabg = get(handles.bgMetodosNumerica,'SelectedObject');
escolha = find([handles.rTrapezio...
          handles.rSimpson]== escolhabg);
      
TRAPEZIO = 1;
SIMPSON = 2;

TestNReal=MException('MATLAB:MyAtualizar:badNreal',...
                      'Introduza um número real');
TestMaior=MException('MATLAB:MyAtualizar:badMaior','O valor do b está incorreto');

TestN = MException('MATLAB:MyAtualizar:badN','O valor do n está incorreto');


try 
    
    if ~(isscalar(a) && isreal(a))
        set(handles.eA,'BackgroundColor','r');
        throw(TestNReal)
    else
        set(handles.eA,'BackgroundColor','w');
    end
    
    if ~(isscalar(b) && isreal(b) && b > a)
        set(handles.eB,'BackgroundColor','r');
        throw(TestMaior)
    else
        set(handles.eB,'BackgroundColor','w');
    end
    
    if ~(isscalar(n) && n == floor(n) && n > 0)
        set(handles.eN,'BackgroundColor','r');
       throw(TestN)
    else
        set(handles.eN,'BackgroundColor','w');
    end
    
  yTrapezio = DI_RTrapezios(f,a,b,n);
  ySimpson = DI_RSimpson(f,a,b,n);
  
        h=(b-a)/n;
		x=a:h:b;
		y=dfdx(x);

		xx=[x,x(end),x(1)];
		yy=[y,0,0];

  
  
  switch(escolha)
        case 1 
            
            plot(yTrapezio,'linewidth',10);
            hold on;
            fill(xx,yy,[0.9290 0.6940 0.1250]);
            set(handles.eQ, 'String', yTrapezio);
            
        case 2
            plot(ySimpson,'linewidth',10);
            hold on;
            fill(xx,yy,[0, 0.4470, 0.7410]);
            set(handles.eQ, 'String', ySimpson);

  end
  grid on 
    xlabel('x')
    ylabel('y')
    hold off 
    clc
catch Me
     errordlg(['Ocorreu um Erro: ' Me.message],'Erro','modal');
end


% --- Executes when user attempts to close figure1.
function figure1_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: delete(hObject) closes the figure
%delete(hObject);
set(hObject,'Visible','Off');