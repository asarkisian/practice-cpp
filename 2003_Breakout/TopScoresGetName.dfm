object inputTopScoresPlayersName: TinputTopScoresPlayersName
  Left = 500
  Top = 437
  BorderIcons = []
  BorderStyle = bsToolWindow
  Caption = 'Congratulations - High Scores List'
  ClientHeight = 147
  ClientWidth = 300
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 2
    Top = 8
    Width = 295
    Height = 49
    AutoSize = False
    Caption = 
      '                CONGRATULATIONS!!!           YOU ARE NOW GOING T' +
      'O BE LISTED ON THE TOP SCORES LIST HALL OF FAME.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    WordWrap = True
  end
  object getName: TLabeledEdit
    Left = 10
    Top = 79
    Width = 281
    Height = 22
    BevelKind = bkSoft
    EditLabel.Width = 285
    EditLabel.Height = 13
    EditLabel.Caption = 'Please type in your name to be listed on the High Scores List'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = []
    LabelPosition = lpAbove
    LabelSpacing = 3
    MaxLength = 15
    ParentFont = False
    TabOrder = 0
  end
  object Button1: TButton
    Left = 10
    Top = 111
    Width = 281
    Height = 25
    Caption = '&OK'
    Default = True
    TabOrder = 1
    OnClick = Button1Click
  end
end
