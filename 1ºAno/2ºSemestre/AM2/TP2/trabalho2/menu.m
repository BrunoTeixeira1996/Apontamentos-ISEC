function varargout = menu(varargin)
% MENU MATLAB code for menu.fig
%      MENU, by itself, creates a new MENU or raises the existing
%      singleton*.
%
%      H = MENU returns the handle to a new MENU or the handle to
%      the existing singleton*.
%
%      MENU('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in MENU.M with the given input arguments.
%
%      MENU('Property','Value',...) creates a new MENU or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before menu_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to menu_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help menu

% Last Modified by GUIDE v2.5 14-May-2020 18:55:06

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @menu_OpeningFcn, ...
                   'gui_OutputFcn',  @menu_OutputFcn, ...
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


% --- Executes just before menu is made visible.
function menu_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to menu (see VARARGIN)

% Choose default command line output for menu
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes menu wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = menu_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in rRK2.
function rRK2_Callback(hObject, eventdata, handles)
% hObject    handle to rRK2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rRK2


% --- Executes on button press in rEuler.
function rEuler_Callback(hObject, eventdata, handles)
% hObject    handle to rEuler (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rEuler


% --- Executes on button press in rRK4.
function rRK4_Callback(hObject, eventdata, handles)
% hObject    handle to rRK4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of rRK4


% --- Executes on button press in radiobutton4.
function radiobutton4_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton4



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



function eG_Callback(hObject, eventdata, handles)
% hObject    handle to eG (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eG as text
%        str2double(get(hObject,'String')) returns contents of eG as a double


% --- Executes during object creation, after setting all properties.
function eG_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eG (see GCBO)
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



function eU_Callback(hObject, eventdata, handles)
% hObject    handle to eU (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eU as text
%        str2double(get(hObject,'String')) returns contents of eU as a double


% --- Executes during object creation, after setting all properties.
function eU_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eU (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function eV_Callback(hObject, eventdata, handles)
% hObject    handle to eV (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eV as text
%        str2double(get(hObject,'String')) returns contents of eV as a double


% --- Executes during object creation, after setting all properties.
function eV_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eV (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in bAtualizar.
function bAtualizar_Callback(hObject, eventdata, handles)
% hObject    handle to bAtualizar (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
MyAtualizar(handles);
% Hint: get(hObject,'Value') returns toggle state of bAtualizar

function MyAtualizar(handles)

strODE = get(handles.eODE2,'String');

a=str2num(get(handles.eA,'String'));
b=str2num(get(handles.eB,'String'));
n=str2num(get(handles.eN,'String'));
u0=str2num(get(handles.eU,'String'));
v0=str2num(get(handles.eV,'String'));



escolhabg = get(handles.bSelect,'SelectedObject');
escolha   = find([handles.rEuler ...
                handles.rRK2 ...
                handles.rRK4...
                handles.rTodos...
                handles.rEulerMelhorado] == escolhabg);
EULER = 1;
RK2   = 2;
RK4   = 3;
TODOS = 4;
EULER_MELHORADO = 5;



sistema_eq = odeToVectorField(strODE);

    tempF = char(sistema_eq(1))
    tempF = replace(replace(tempF, 'Y[1]', 'u'), 'Y[2]', 'v')
    tempG = char(sistema_eq(2))
    tempG = replace(replace(tempG, 'Y[1]', 'u'), 'Y[2]', 'v')
    f = matlabFunction(str2sym(tempF),'vars',{'t','u','v'})
    g = matlabFunction(str2sym(tempG),'vars',{'t','u','v'})

    set(handles.eF,'String',tempF)
    set(handles.eG,'String',tempG)
    
    [tExata, sExata] = SolExata(strODE, a, b, n, u0, v0);
    [tEuler, uEuler, vEuler] = NEulerSED(f,g,a,b,n,u0,v0);
    [tRK2, uRK2, vRK2]   = NRK2SED(f,g,a,b,n,u0,v0);
    [tRK4, uRK4, vRK4]   = NRK4SED(f,g,a,b,n,u0,v0);
    [tEulerM, uEulerM, vEulerM] = NEuler_Melhorada(f,g,a,b,n,u0,v0);
    
    
    if(~isempty(sExata))
        plot(tExata, sExata)
        hold on
    end
    switch(escolha)
        case EULER
            if(~isempty(sExata))
                plot(tEuler,uEuler,'color',[0.6350 0.0780 0.1840])
                plot(tEuler,vEuler,'color',[0.9290 0.6940 0.1250])
                legend({'Exata', 'Euler', 'Velocidade'})  
                set(handles.uiTabela,'ColumnName',[{'t'},...
                {'Euler'},{'Velocidade'},{'Exata'}, {'Erro Euler'}]);

                cTabela = [tEuler.', uEuler.',vEuler.', sExata.', abs(uEuler-sExata).'];     
            else
                plot(tEuler,uEuler,'color',[0.6350 0.0780 0.1840])
                hold on
                plot(tEuler,vEuler,'color',[0.9290 0.6940 0.1250])
                legend({'Euler', 'Velocidade'}) 
                set(handles.uiTabela,'ColumnName',[{'t'},...
                    {'Velocidade'},{'Euler'}])

                cTabela = [tEuler.', uEuler.',vEuler.'];      
            end
            set(handles.uiTabela,'Data',num2cell(cTabela));
            
        case RK2
            if(~isempty(sExata))
                plot(tRK2,uRK2,'color',[0.6350 0.0780 0.1840])
                plot(tRK2,vRK2,'color',[0.9290 0.6940 0.1250])
                legend({'Exata', 'RK2', 'Velocidade'})       
                set(handles.uiTabela,'ColumnName',[{'t'},...
                    {'RK2'},{'Velocidade'},{'Exata'}, {'Erro RK2'}])

                cTabela = [tRK2.', uRK2.',vRK2.', sExata.', abs(uRK2-sExata).'];
            else
                plot(tRK2,uRK2,'color',[0.6350 0.0780 0.1840])
                hold on
                plot(tRK2,vRK2,'color',[0.9290 0.6940 0.1250])
                legend({'RK2', 'Velocidade'})      
                set(handles.uiTabela,'ColumnName',[{'t'}, {'RK2'},{'Velocidade'}]);

                cTabela = [tRK2.', uRK2.',vRK2.']; 
            end
            set(handles.uiTabela,'Data',num2cell(cTabela));
        case RK4
            if(~isempty(sExata))
                plot(tRK4,uRK4,'color',[0.6350 0.0780 0.1840])
                plot(tRK4,vRK4,'color',[0.9290 0.6940 0.1250])
                legend({'Exata', 'RK4', 'Velocidade'})  
                set(handles.uiTabela,'ColumnName',[{'t'},...
                    {'RK4'},{'Velocidade'},{'Exata'}, {'Erro RK4'}]);

                cTabela = [tRK4.', uRK4.',vRK4.', sExata.', abs(uRK4-sExata).'];     
            else
                plot(tRK4,uRK4,'color',[0.6350 0.0780 0.1840])
                hold on
                plot(tRK4,vRK4,'color',[0.9290 0.6940 0.1250])
                legend({'RK4', 'Velocidade'})  
                set(handles.uiTabela,'ColumnName',[{'t'}, {'RK4'},{'Velocidade'}]);

                cTabela = [tRK4.', uRK4.',vRK4.'];     
            end
            set(handles.uiTabela,'Data',num2cell(cTabela))
        case TODOS
            if(~isempty(sExata))
                plot(tEuler,uEuler)
                plot(tEulerM, uEulerM)
                plot(tRK2,uRK2)
                plot(tRK4,uRK4)

                legend({'Exata', 'Euler', 'Euler Melhorado', 'RK2', 'RK4'})
                set(handles.uiTabela,'ColumnName',[{'t'}, ...
                    {'Euler'},{'Euler Melhorado'},{'RK2'},{'RK4'},{'Exata'},...
                    {'Erro Euler'},{'Erro Euler Melhorado'},{'Erro RK2'},{'Erro RK4'}]);

                cTabela = [tEuler.', uEuler.', uEulerM.', uRK2.', uRK4.', sExata.',...
                     abs(uEuler-sExata).', abs(uEulerM-sExata).', abs(uRK2-sExata).', abs(uRK4-sExata).'];
            else
                plot(tEuler,uEuler,'color',[0,0.7,0.9])
                hold on
                plot(tEulerM, uEulerM, 'color',[0.8500 0.3250 0.0980])
                plot(tRK2,uRK2,'color',[0.6350 0.0780 0.1840])
                plot(tRK4,uRK4,'color',[0.4940 0.1840 0.5560])

                legend({'Euler', 'Euler Melhorado', 'RK2', 'RK4'})
                set(handles.uiTabela,'ColumnName',[{'t'}, ...
                    {'Euler'},{'Euler Melhorado'},{'RK2'},{'RK4'}])

                cTabela = [tEuler.', uEuler.', uEulerM.', uRK2.', uRK4.'];
            end
            
            set(handles.uiTabela,'Data',num2cell(cTabela));
            
            case EULER_MELHORADO
            if(~isempty(sExata))
                plot(tEulerM,uEulerM,'color',[0.6350 0.0780 0.1840])
                plot(tEulerM,vEulerM,'color',[0.9290 0.6940 0.1250])
                legend({'Exata', 'Euler Melhorado', 'Velocidade'})     
                set(handles.uiTabela,'ColumnName',[{'t'},...
                    {'Euler Melhorado'},{'Velocidade'},{'Exata'}, {'Erro Euler Melhorado'}])

                cTabela = [tEulerM.', uEulerM.',vEulerM.',sExata.', abs(uEulerM-sExata).']; 
            else
                plot(tEulerM,uEulerM,'color',[0.6350 0.0780 0.1840])
                hold on
                plot(tEulerM,vEulerM,'color',[0.9290 0.6940 0.1250])
                legend({'Euler Melhorado', 'Velocidade'})       
                set(handles.uiTabela,'ColumnName',[{'t'},...
                   {'Velocidade'}, {'Euler Melhorado'}])

                cTabela = [tEulerM.', uEulerM.',vEulerM.'];
            end
            set(handles.uiTabela,'Data',num2cell(cTabela));
            
    end
    grid on
    hold off
    xlabel('t')
    ylabel('y')
    
    
     



% --- Executes during object creation, after setting all properties.
function rEuler_CreateFcn(hObject, eventdata, handles)
% hObject    handle to rEuler (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes when selected object is changed in bSelect.
function bSelect_SelectionChangedFcn(hObject, eventdata, handles)
% hObject    handle to the selected object in bSelect 
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
MyAtualizar(handles);



function eODE2_Callback(hObject, eventdata, handles)
% hObject    handle to eODE2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of eODE2 as text
%        str2double(get(hObject,'String')) returns contents of eODE2 as a double


% --- Executes during object creation, after setting all properties.
function eODE2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to eODE2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --------------------------------------------------------------------
function menuAutores_Callback(hObject, eventdata, handles)
% hObject    handle to menuAutores (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
autores


% --------------------------------------------------------------------
function menuProblemas_Callback(hObject, eventdata, handles)
% hObject    handle to menuProblemas (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function menuPendulo_Callback(hObject, eventdata, handles)
% hObject    handle to menuPendulo (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

set(handles.eQ, 'String', 'D2y+(c/(m*L))*Dy+(g/L)*sin(y)=0');
set(handles.eODE2,'String', 'D2y+(3/(1*10))*Dy+sin(y)=0');
set(handles.eU,'String', 'pi/2');
set(handles.eV,'String', '0');
set(handles.eA,'String', '0');
set(handles.eB,'String', '15');
set(handles.eN,'String', '100');

MyAtualizar(handles)

% --------------------------------------------------------------------
function menuMolaMassa_A_Callback(hObject, eventdata, handles)
% hObject    handle to menuMolaMassa_A (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.eQ, 'String', 'm*D2y+b*Dy+k*y=h(t)');
set(handles.eODE2,'String', 'D2y+10*Dy+20*y=cos(t)');
set(handles.eU,'String', '0');
set(handles.eV,'String', '0');
set(handles.eA,'String', '0');
set(handles.eB,'String', '15');
set(handles.eN,'String', '100');

MyAtualizar(handles)

% --------------------------------------------------------------------
function menuMolaMassa_SA_Callback(hObject, eventdata, handles)
% hObject    handle to menuMolaMassa_SA (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

set(handles.eQ, 'String', 'm*D2y+k*y=h(t)');
set(handles.eODE2,'String', 'D2y+20*y=cos(t)');
set(handles.eU,'String', '1');
set(handles.eV,'String', '0');
set(handles.eA,'String', '0');
set(handles.eB,'String', '15');
set(handles.eN,'String', '100');

MyAtualizar(handles)
% --------------------------------------------------------------------
function menuCircuito_Callback(hObject, eventdata, handles)
% hObject    handle to menuCircuito (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.eQ, 'String', 'L*D2y+r*Dy+(1/c)*y=h(t)');
set(handles.eODE2,'String', '5*D2y+10*Dy+(1/3)*y=cos(t)');
set(handles.eU,'String', '0');
set(handles.eV,'String', '0');
set(handles.eA,'String', '0');
set(handles.eB,'String', '15');
set(handles.eN,'String', '100');


MyAtualizar(handles)
