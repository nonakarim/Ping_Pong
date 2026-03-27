#include <iostream>
#include "raylib.h"

struct Declarations{
    Texture2D start = LoadTexture("assets/images/Start.png");
    Rectangle startRec = {0, 0, 283, 114};

    Texture2D stop = LoadTexture("assets/images/Stop.png");
    Rectangle stopRec = {0, 0, 294, 144};

    Rectangle startDestRec;
    Rectangle stopDestRec;

    Image icon = LoadImage("assets/images/Icon.png");

    Texture2D Bg = LoadTexture("assets/images/Bg.png");
    Rectangle BgRec = {0, 0, 484, 260};
    Rectangle BgDestRec;

    Texture2D Paddle1 = LoadTexture("assets/images/Paddle1.png");
    Rectangle Paddle1Rec = {0, 0, 239, 391};
    Rectangle Paddle1DestRec;

    Texture2D Paddle2 = LoadTexture("assets/images/Paddle2.png");
    Rectangle Paddle2Rec = {0, 0, 194, 345};
    Rectangle Paddle2DestRec;

    Texture2D Ball = LoadTexture("assets/images/Ball.png");
    Rectangle BallRec = {0, 0, 254, 266};
    Rectangle BallDestRec;

    Texture2D UseMouse = LoadTexture("assets/images/Use mouse.png");
    Rectangle UseMouseSrc = {0, 0, 492, 138};
    Rectangle UseMouseDest;

    Texture2D UseKeyboard = LoadTexture("assets/images/Use keyboard.png");
    Rectangle UseKeyboardSrc = {0, 0, 492, 138};
    Rectangle UseKeyboardDest;

    Sound hit = LoadSound("assets/audio/PaddleHit.mp3");
    Sound win = LoadSound("assets/audio/win.mp3");
    Sound lose = LoadSound("assets/audio/Lose.mp3");
    Sound pickOne = LoadSound("assets/audio/PickOne.wav");
    Music gamePlay = LoadMusicStream("assets/audio/GamePlay.mp3");

    void throwExceptions()
    {
        if(start.id == 0)
            throw "Start texture hadn't loaded";
        if(stop.id == 0)
            throw "Stop texture hadn't loaded";
        if(Bg.id == 0)
            throw "Bg texture hadn't loaded";
        if(Paddle1.id == 0)
            throw "Paddle1 texture hadn't loaded";
        if(Paddle2.id == 0)
            throw "Paddle2 texture hadn't loaded";
        if(Ball.id == 0)
            throw "Ball texture hadn't loaded";
        if(UseMouse.id == 0)
            throw "UseMouse texture hadn't loaded";
        if(UseKeyboard.id == 0)
            throw "UseKeyboard texture hadn't loaded";
        if(icon.data == NULL || icon.width == 0 || icon.height == 0)
            throw "icon texture hadn't loaded";
    }

    void destroy()
    {
        UnloadTexture(start);
        UnloadTexture(stop);
        UnloadImage(icon);
        UnloadTexture(Paddle1);
        UnloadTexture(Paddle2);
        UnloadTexture(Ball);
        UnloadTexture(UseMouse);
        UnloadTexture(UseKeyboard);
        UnloadSound(hit);
    }
};