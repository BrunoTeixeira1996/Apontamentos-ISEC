function varargout = autores(varargin)
% AUTORES MATLAB code for autores.fig
%      AUTORES, by itself, creates a new AUTORES or raises the existing
%      singleton*.
%
%      H = AUTORES returns the handle to a new AUTORES or the handle to
%      the existing singleton*.
%
%      AUTORES('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in AUTORES.M with the given input arguments.
%
%      AUTORES('Property','Value',...) creates a new AUTORES or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before autores_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to autores_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help autores

% Last Modified by GUIDE v2.5 24-Apr-2020 16:14:26

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @autores_OpeningFcn, ...
                   'gui_OutputFcn',  @autores_OutputFcn, ...
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


% --- Executes just before autores is made visible.
function autores_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to autores (see VARARGIN)

% Choose default command line output for autores
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);
axes(handles.axes1);
imshow('bruno.jpg');
axes(handles.axes2);
imshow('rafa.jpg');
axes(handles.axes3);
imshow('gon.jpeg');
axes(handles.axes4);
imshow('sofia.jpg');
% UIWAIT makes autores wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = autores_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;
