object frmGamePause: TfrmGamePause
  Left = 495
  Top = 438
  BorderIcons = [biSystemMenu]
  BorderStyle = bsNone
  ClientHeight = 51
  ClientWidth = 574
  Color = clBtnFace
  TransparentColor = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poDefault
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 111
    Top = -8
    Width = 355
    Height = 56
    Caption = 'PAUSED GAME'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -48
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 226
    Top = 38
    Width = 112
    Height = 13
    Caption = 'Press <F5> to  unpause'
  end
end
