 //
//  test.cpp
//  libRealSpace
//
//  Created by Fabien Sanglard on 12/28/2013.
//  Copyright (c) 2013 Fabien Sanglard. All rights reserved.
//

#include "precomp.h"

static RSScreen Screen;
static RSVGA VGA;


void testTRE(void){
    
    TreArchive treArchive;
    treArchive.InitFromFile("OBJECTS.TRE");
    treArchive.List(stdout);
    
}






void testPalette(void){
    
    IffLexer lexer ;
    lexer.InitFromFile("PALETTE.IFF");
    lexer.List(stdout);
    
    RSPalette palette;
    palette.InitFromIFF(&lexer);
}

void testTREDecompress(const char* dst){
    
   // const char* trePath = "GAMEFLOW.TRE";
   // const char* trePath = "MISC.TRE";
   // const char* trePath = "MISSIONS.TRE";
   // const char* trePath = "OBJECTS.TRE";
   // const char* trePath = "SOUND.TRE";
    const char* trePath = "TEXTURES.TRE";
   
    
    TreArchive treArchive;
    treArchive.InitFromFile(trePath);
    treArchive.Decompress(dst);
}

void testPAKDecompress(void){
    
    const char* trePath = "GAMEFLOW.TRE";
    TreArchive treArchive;
    treArchive.InitFromFile(trePath);
    
    treArchive.List(stdout);
    
    //Find the sounds PAKS.
    const char* pakName = "..\\..\\DATA\\MIDGAMES\\MID1VOC.PAK";
    TreEntry* treEntry = treArchive.GetEntryByName(pakName);
    
    
    PakArchive pakArchive;
    pakArchive.InitFromRAM(pakName,treEntry->data, treEntry->size);
    
    //Decompress it
    pakArchive.Decompress(".","VOC");
}



void testParsePAK(){
    PakArchive archive;
    archive.InitFromFile("MAURITAN.PAK");
    
    archive.List(stdout);
}






void ExploreRootIFFS(void){
    
    //IffLexer instant;
    //instant.InitFromFile("INSTANT.IFF");
    //instant.List(stdout);
    
    IffLexer misn2op;
    misn2op.InitFromFile("MISN2OP.IFF");
    misn2op.List(stdout);
    
    
    IffLexer opt2misn;
    opt2misn.InitFromFile("OP2MISN.IFF");
    opt2misn.List(stdout);
    
    
    IffLexer palette;
    palette.InitFromFile("PALETTE.IFF");
    palette.List(stdout);
    
    
    IffLexer palFade;
    palFade.InitFromFile("PALFADE.IFF");
    palFade.List(stdout);
    
    IffLexer txmList;
    txmList.InitFromFile("TXM_LIST.IFF");
    txmList.List(stdout);
    
    
    
    PakArchive eject;
    eject.InitFromFile("EJECT.PAK");
    eject.List(stdout);
    eject.Decompress("/Users/fabiensanglard/Desktop/DATA/OBJECTS/EJECT/", "TXT");
    
    SetBase("/Users/fabiensanglard/Desktop/DATA/OBJECTS/EJECT/EJECT.PAK.CONTENT");
    
    PakArchive file0;
    file0.InitFromFile("FILE0.TXT");
    file0.List(stdout);
    file0.Decompress("/Users/fabiensanglard/Desktop/DATA/OBJECTS/EJECT/EJECT.PAK.CONTENT/FILE0", "TXT");


    PakArchive file1;
    file1.InitFromFile("FILE1.TXT");
    file1.List(stdout);
    file1.Decompress("/Users/fabiensanglard/Desktop/DATA/OBJECTS/EJECT/EJECT.PAK.CONTENT/FILE1", "TXT");


    PakArchive file2;
    file2.InitFromFile("FILE2.TXT");
    file2.List(stdout);
    file2.Decompress("/Users/fabiensanglard/Desktop/DATA/OBJECTS/EJECT/EJECT.PAK.CONTENT/FILE2", "TXT");
    
    PakArchive file3;
    file3.InitFromFile("FILE3.TXT");
    file3.List(stdout);
    file3.Decompress("/Users/fabiensanglard/Desktop/DATA/OBJECTS/EJECT/EJECT.PAK.CONTENT/FILE3", "TXT");
    
    PakArchive file4;
    file4.InitFromFile("FILE4.TXT");
    file4.List(stdout);
    file4.Decompress("/Users/fabiensanglard/Desktop/DATA/OBJECTS/EJECT/EJECT.PAK.CONTENT/FILE4", "TXT");
    
    PakArchive file5;
    file5.InitFromFile("FILE5.TXT");
    file5.List(stdout);
    file5.Decompress("/Users/fabiensanglard/Desktop/DATA/OBJECTS/EJECT/EJECT.PAK.CONTENT/FILE5", "TXT");
    
    PakArchive file6;
    file6.InitFromFile("FILE6.TXT");
    file6.List(stdout);
    file6.Decompress("/Users/fabiensanglard/Desktop/DATA/OBJECTS/EJECT/EJECT.PAK.CONTENT/FILE6", "TXT");
    
    PakArchive file7;
    file7.InitFromFile("FILE7.TXT");
    file7.List(stdout);
    file7.Decompress("/Users/fabiensanglard/Desktop/DATA/OBJECTS/EJECT/EJECT.PAK.CONTENT/FILE7", "TXT");
    
    PakArchive file8;
    file8.InitFromFile("FILE8.TXT");
    file8.List(stdout);
    file8.Decompress("/Users/fabiensanglard/Desktop/DATA/OBJECTS/EJECT/EJECT.PAK.CONTENT/FILE8", "TXT");
}

void decompressTREs(const char* path){
    TreArchive gameFlow ;
    gameFlow.InitFromFile("GAMEFLOW.TRE");
    gameFlow.Decompress(path);
    
    TreArchive misc ;
    misc.InitFromFile("MISC.TRE");
    misc.Decompress(path);
    
    TreArchive mission ;
    mission.InitFromFile("MISSIONS.TRE");
    mission.Decompress(path);
    
    TreArchive objects ;
    objects.InitFromFile("OBJECTS.TRE");
    objects.Decompress(path);
    
    TreArchive sound ;
    sound.InitFromFile("SOUND.TRE");
    sound.Decompress(path);
    
    TreArchive textures ;
    textures.InitFromFile("TEXTURES.TRE");
    textures.Decompress(path);
    

}

void listTRE(void){

    
    TreArchive gameFlow ;
    gameFlow.InitFromFile("GAMEFLOW.TRE");
    gameFlow.List(stdout);

    TreArchive misc ;
    misc.InitFromFile("MISC.TRE");
    misc.List(stdout);

    TreArchive mission ;
    mission.InitFromFile("MISSIONS.TRE");
    mission.List(stdout);
    
    TreArchive objects ;
    objects.InitFromFile("OBJECTS.TRE");
    objects.List(stdout);
    
    TreArchive sound ;
    sound.InitFromFile("SOUND.TRE");
    sound.List(stdout);

    TreArchive textures ;
    textures.InitFromFile("TEXTURES.TRE");
    textures.List(stdout);
    
}


void PrintTabs(int tabs){
    for (size_t i=0 ; i < tabs; i++) {
        printf(" ");
    }
}

#define imgSpeed 1000000
void ExploreImages(uint8_t* data, size_t size, int numTabs){
    
    PrintTabs(numTabs);
    printf("Exploring 0X%X\n",data);
        
    //SHP files are PAKs containing direct images.
    PakArchive font;
    font.InitFromRAM("XXXX",data,size);
    if (font.IsReady()){
        font.List(stdout);
        PrintTabs(numTabs);
        printf("Pak Found 0X%X\n",data);
        for(size_t i =0 ; i  < font.GetNumEntries() ; i++){
            PakEntry* e = font.GetEntry(i);
            PrintTabs(numTabs);
            printf("Pak entry %lu\n",i);
            ExploreImages(e->data,e->size,numTabs+1);
            
        }
        return;
    }
    
    
    //Myabe it is a direct image ?
    RLEShape shape;
    shape.Init(data, size);
    
    bool errorFound;
    VGA.Clear();
    errorFound = VGA.DrawShape(&shape);
    if (!errorFound){
        VGA.VSync();
        Screen.Refresh();
        usleep(imgSpeed);
        PrintTabs(numTabs);
        printf("Image Found 0X%X\n",data);
        return;
    }
    
    
    //TODO there is palette at the end of the sequence of images. It should be retrieved.
    //Maybe it is a sequence of images ?
    uint8_t* end = data + size;
    ByteStream s(data);
    uint32_t nextImage = s.ReadUInt32LE();
    nextImage = nextImage & 0x00FFFFFF;
    
    if (data + nextImage >= end)
        return;
    
    uint32_t numImages = nextImage/4 ;
    for(size_t i = 0 ; i < numImages && (data+nextImage < end) ; i++){
        
        RLEShape shape;
        shape.Init(data+nextImage, size);
        
        bool errorFound;
        VGA.Clear();
        errorFound = VGA.DrawShape(&shape);
        if (!errorFound){
            VGA.VSync();
            Screen.Refresh();
            usleep(imgSpeed);
            PrintTabs(numTabs);
            printf("Image Found 0X%X\n",data+nextImage);
            
        }
        //else
          //  return;
        
        nextImage = s.ReadUInt32LE();
        nextImage = nextImage & 0x00FFFFFF;
    }
    
}

void TestMouseCursor(void){
    
    SetBase("/Users/fabiensanglard/SC/SC/");
    Screen.Init(2);
    VGA.Init();
    VGA.Activate();
    
    
    TreArchive gameflow ; gameflow.InitFromFile("GAMEFLOW.TRE");
    TreArchive misc ;     misc.InitFromFile("MISC.TRE");
    TreArchive mis ;      mis.InitFromFile("MISSIONS.TRE");
    TreArchive obj ;      obj.InitFromFile("OBJECTS.TRE");
    
    
     TreEntry* mainFont = gameflow.GetEntryByName("..\\..\\DATA\\MIDGAMES\\MID1.PAK"); //Camera configuration
     //ExploreImages(mainFont->data,mainFont->size,0);
     
    
    
    
    
    TreEntry* camropt = misc.GetEntryByName("..\\..\\DATA\\FONTS\\CAMROPT.SHP"); //Camera configuration
    //ExploreImages(camropt->data,camropt->size,0);

    
    
   
     TreEntry* chkexit = misc.GetEntryByName("..\\..\\DATA\\FONTS\\CHKEXIT.SHP"); //Exit to DOS configuration
     //ExploreImages(chkexit->data,chkexit->size,0);
    
    
    
  
    TreEntry* cockopt = misc.GetEntryByName("..\\..\\DATA\\FONTS\\COCKOPT.SHP"); // Cockpit configuration
    //ExploreImages(cockopt->data,cockopt->size,0);
    
    
    
     TreEntry* convFont = misc.GetEntryByName("..\\..\\DATA\\FONTS\\CONVFONT.SHP"); // Unknown but likely a font wiht 128 entries
    //ExploreImages(convFont->data,convFont->size,0);
    
    
    
    
    
     TreEntry* detlopt = misc.GetEntryByName("..\\..\\DATA\\FONTS\\DETLOPT.SHP"); // Details options
     //ExploreImages(detlopt->data,detlopt->size);
    
    
    
   
    TreEntry* FLITOPT = misc.GetEntryByName("..\\..\\DATA\\FONTS\\FLITOPT.SHP"); // Control options
    //ExploreImages(FLITOPT->data,FLITOPT->size,0);
    
    
    

    TreEntry* FORMFONT = misc.GetEntryByName("..\\..\\DATA\\FONTS\\FORMFONT.SHP"); // Font option
    //ExploreImages(FORMFONT->data,FORMFONT->size);
    
    
    

    TreEntry* GAMEOPT = misc.GetEntryByName("..\\..\\DATA\\FONTS\\GAMEOPT.SHP"); // Gameplay option
    //ExploreImages(GAMEOPT->data,GAMEOPT->size);
    
    
    
    
    TreEntry* GRAVFONT = misc.GetEntryByName("..\\..\\DATA\\FONTS\\GRAVFONT.SHP"); // Gameplay option
    //ExploreImages(GRAVFONT->data,GRAVFONT->size);
    
    
    
  
    TreEntry* MENBGRND = misc.GetEntryByName("..\\..\\DATA\\FONTS\\MENBGRND.SHP"); // DogFight background
   // ExploreImages(MENBGRND->data,MENBGRND->size,0);
    
    
    
  
    TreEntry* MTYPEBUT = misc.GetEntryByName("..\\..\\DATA\\FONTS\\MTYPEBUT.SHP"); // Dogfight/Search&Destroy ...WHY is is duplicated from MAINMENU.PAK??
    //ExploreImages(MTYPEBUT->data,MTYPEBUT->size,0);
    
    
    
  
    TreEntry* OVBKGRND = misc.GetEntryByName("..\\..\\DATA\\FONTS\\OVBKGRND.SHP"); // Object Viewer background ...WHY is is duplicated from OBJVIEW.PAK??
    //ExploreImages(OVBKGRND->data,OVBKGRND->size,0);
    
    
    
 
    TreEntry* RESTART = misc.GetEntryByName("..\\..\\DATA\\FONTS\\RESTART.SHP"); // Restart menu
    //ExploreImages(RESTART->data,RESTART->size,0);
    
    
    
    TreEntry* BETTY = mis.GetEntryByName("..\\..\\DATA\\COCKPITS\\BETTY.PAK");    // ?
    //ExploreImages(BETTY->data,BETTY->size,0);
    
    
    

    TreEntry* mid1 = gameflow.GetEntryByName("..\\..\\DATA\\MIDGAMES\\MIDGAMES.PAK");
   // ExploreImages(mid1->data,mid1->size,0);
    
    
    

    TreEntry* tm = gameflow.GetEntryByName("..\\..\\DATA\\GAMEFLOW\\TM.SHP");  //Training mission builder dialog
    //ExploreImages(tm->data,tm->size,0);
    
    
    

    TreEntry* MAINMENU = gameflow.GetEntryByName("..\\..\\DATA\\GAMEFLOW\\MAINMENU.PAK");  //Main Menu buttons. No background :( !
    //ExploreImages(MAINMENU->data,MAINMENU->size,0);
    
    
    
    
    TreArchive gf ;
    gf.InitFromFile("GAMEFLOW.TRE");
    TreEntry* CONVSHPS = gameflow.GetEntryByName("..\\..\\DATA\\GAMEFLOW\\CONVSHPS.PAK");  // ALL SETS AND CHARACTERS !!!!!
    ExploreImages(CONVSHPS->data,CONVSHPS->size,0);
    
    //Check palettes fro that too
    /*
    TreEntry* palettesEConv = gf.GetEntryByName("..\\..\\DATA\\GAMEFLOW\\CONVPALS.PAK");
    PakArchive palettesArchiveConv ;
    palettesArchiveConv.InitFromRAM("CONVPALS.PAK", palettesEConv->data, palettesEConv->size);
    palettesArchiveConv.List(stdout);
    */
    

    
   
    TreEntry* optShps = gameflow.GetEntryByName("..\\..\\DATA\\GAMEFLOW\\OPTSHPS.PAK");  // A LLOOOOOOT OF GOOOD STUFFF !!! Background, bar animations, all airplanes
                                                                                // airplane preparation,
    /*
        118 - > female pinup
        119 -> wild cat base entry
        119 -> deset landing strip
     
     17 jeep animation
     18 wildcat hangar
     20 truck animatiopn
     22 accountant anim
     25 tent background
     35 36 people hangar top down animations
     
     40  f16
     41
     
     50 werapons buttons
     90
     91 f-16 weapon selection
     
     128 map north america
     129 map south america
     130 map europe
     131 map africa
     */
    
    
    ExploreImages(optShps->data,optShps->size,0);

    //Check palettes fro that too
    /*
    TreEntry* palettesE = gf.GetEntryByName("..\\..\\DATA\\GAMEFLOW\\OPTPALS.PAK");
    PakArchive palettesArchive ;
    palettesArchive.InitFromRAM("OPTPALS.PAK", palettesE->data, palettesE->size);
    palettesArchive.List(stdout);
    */
    
    
    
    
    
   
    TreEntry* MAINOPT = misc.GetEntryByName("..\\..\\DATA\\FONTS\\MAINOPT.SHP");
    //ExploreImages(MAINOPT->data,MAINOPT->size,0);
     
    
    
    
    TreEntry* objE = obj.GetEntryByName("..\\..\\DATA\\OBJECTS\\EJECT.PAK");   //Eject/Crash animation
    //ExploreImages(objE->data,objE->size,0);
    
}

void ReverseOBKViewButton(){
    SetBase("/Users/fabiensanglard/SC/SC/");
    Screen.Init(2);
    VGA.Init();
    VGA.Activate();
    
    TreArchive tre ;
    tre.InitFromFile("GAMEFLOW.TRE");
    TreEntry* e = tre.GetEntryByName("..\\..\\DATA\\GAMEFLOW\\OBJVIEW.PAK");
//    ExploreImages(e->data, e->size, 0);
    
    TreArchive misc ;
    misc.InitFromFile("MISC.TRE");
    misc.List(stdout);
    TreEntry* MAINOPT = tre.GetEntryByName("..\\..\\DATA\\GAMEFLOW\\TM.SHP");
    ExploreImages(MAINOPT->data,MAINOPT->size,0);

}

#define GROUP_SHOT              0x00
#define GROUP_SHOT_ADD_CHARCTER 0x01
#define GROUP_SHOT_CHARCTR_TALK 0x02
#define CLOSEUP                 0x03
#define CLOSEUP_CONTINUATION    0x04
#define SHOW_TEXT               0x0A
#define YESNOCHOICE_BRANCH1     0x0B
#define YESNOCHOICE_BRANCH2     0x0C
#define UNKNOWN                 0x0E
#define CHOOSE_WINGMAN          0x0F

int32_t ParsePlan(ByteStream* reader){
    
    uint8_t* startPos = reader->GetPosition();
    
    uint8_t type = reader->ReadByte();
    
    switch (type) {
        case GROUP_SHOT:  // Group plan
        {
            char* location = (char*)reader->GetPosition();
            printf("WIDEPLAN : LOCATION: '%s'\n",location);
            reader->MoveForward(8+1);
            break;
        }
        case CLOSEUP:  // Person talking
        {
            uint8_t* speakerName = reader->GetPosition();
            uint8_t* set         = reader->GetPosition() + 0xA;
            uint8_t* sentence         = reader->GetPosition() + 0x17;
            
            
            reader->MoveForward(0x17 + strlen((char*)sentence)+1);
            uint8_t color = reader->ReadByte(); // Color ?
            
            printf("CLOSEUP: WHO: '%8s' WHERE: '%8s'     WHAT: '%s' (%2X)\n",speakerName,set,sentence,color);
            break;
        }
        case CLOSEUP_CONTINUATION:  // Same person keep talking
        {
            uint8_t* sentence         = reader->GetPosition();
            reader->MoveForward(strlen((char*)sentence)+1);
            printf("MORETEX:                                       WHAT: '%s'\n",sentence);
            break;
        }
        case YESNOCHOICE_BRANCH1:  // Choice Offsets are question
        {
            printf("CHOICE YES/NO : %X.\n",type);
            //Looks like first byte is the offset to skip if the answer is no.
            uint8_t noOffset  = reader->ReadByte();
            uint8_t yesOffset  = reader->ReadByte();
            break;
        }
        case YESNOCHOICE_BRANCH2:  // Choice offset after first branch
        {
            printf("CHOICE YES/NO : %X.\n",type);
            //Looks like first byte is the offset to skip if the answer is no.
            uint8_t yesOffset  = reader->ReadByte();
            uint8_t noOffset  = reader->ReadByte();
            break;
        }
        case GROUP_SHOT_ADD_CHARCTER:  // Add person to GROUP
        {
            printf("WIDEPLAN ADD PARTICIPANT: '%s'\n",reader->GetPosition());
            reader->MoveForward(0xD);
            break;
        }
        case GROUP_SHOT_CHARCTR_TALK:  // Make group character talk
        {
            char* who = (char*)reader->GetPosition();
            reader->MoveForward(0xE);
            char* sentence = (char*)reader->GetPosition();
            reader->MoveForward(strlen(sentence)+1);
            printf("WIDEPLAN PARTICIPANT TALKING: who: '%s' WHAT '%s'\n",who,sentence);


            break;
        }
        case SHOW_TEXT:  // Show text
        {
            uint8_t color = reader->ReadByte();
            char* sentence = (char*)reader->GetPosition();
            printf("Show Text: '%s' \n",sentence);
            reader->MoveForward(strlen(sentence)+1);
            
            break;
        }
        case 0xE:
        {
            uint8_t unkn  = reader->ReadByte();
            uint8_t unkn1  = reader->ReadByte();
            printf("Unknown usage Flag 0xE: (0x%2X 0x%2X) \n",unkn,unkn1);
            break;
        }
        case CHOOSE_WINGMAN:  // Wingman selection trigger
        {
            printf("Open pilot selection screen with currennt BG.\n");
            break;
        }
        default:
            printf("Unknown opcode: %X.\n",type);
            return 9999;
            break;
    }
    
    
    return reader->GetPosition() - startPos;
}

void ParseConv(PakEntry* conv){
    
    if (conv->size == 0)
        return;
    
    
    
    ByteStream planReader ;
    planReader.Set(conv->data);
    
    int32_t byteToRead = conv->size;
    while(byteToRead > 0){
        int32_t byteRead = ParsePlan(&planReader);
        byteToRead -= byteRead;
    }
    
}

void ParseAllConversations(){
    
    SetBase("/Users/fabiensanglard/SC/SC/");

    
    
    TreArchive gameFlow ;
    gameFlow.InitFromFile("GAMEFLOW.TRE");
    
    TreEntry* metaConfEntry = gameFlow.GetEntryByName("..\\..\\DATA\\GAMEFLOW\\CONVDATA.IFF");
    IffLexer iffConData ;
    iffConData.InitFromRAM(metaConfEntry->data, metaConfEntry->size);
    //
    //iffConData.List(stdout);
    
    TreEntry* convPalettesEntry = gameFlow.GetEntryByName("..\\..\\DATA\\GAMEFLOW\\CONVPALS.PAK");
    PakArchive convPalettePak;
    convPalettePak.InitFromRAM("CONVPALS.PAK", convPalettesEntry->data, convPalettesEntry->size);
  //  convPalettePak.List(stdout);
    
    
    TreEntry* convEntry = gameFlow.GetEntryByName("..\\..\\DATA\\GAMEFLOW\\CONV.PAK");
    
    PakArchive convPak;
    convPak.InitFromRAM("CONV.PAK", convEntry->data, convEntry->size);
    //convPak.List(stdout);
    
    for (size_t i = 0; i < convPak.GetNumEntries(); i++) {
    //for (size_t i = 12; i < 13; i++) {
        if (convPak.GetEntry(i)->size == 0){
            printf("\nConversation: %lu : EMPTY ENTRY.\n",i);
            continue;
        }
        printf("\nConversation: %lu :\n",i);
        ParseConv(convPak.GetEntry(i));
    }
    
    /*
    TreEntry* convShapesEntry = gameFlow.GetEntryByName("..\\..\\DATA\\GAMEFLOW\\CONVSHPS.PAK");
    PakArchive convShapesPak;
    convShapesPak.InitFromRAM("CONVSHPS.PAK", convShapesEntry->data, convShapesEntry->size);
    convShapesPak.List(stdout);
    for (size_t i =0 ; i < convShapesPak.GetNumEntries(); i++) {
        PakEntry* shape = convShapesPak.GetEntry(i);
        PakArchive tmp;
        tmp.InitFromRAM("", shape->data, shape->size);
        if (tmp.IsReady())
            printf("CONVSHPS.PAK entry %lu has %d entries.\n",i,tmp.GetNumEntries());
        else
            printf("CONVSHPS.PAK entry %lu is not a PAK.\n",i);
    }
    */
}

int mainTest( int argc,char** argv){
    
    ParseAllConversations();
    return 0;
    
   // ReverseOBKViewButton();
    //TestMouseCursor();
    
    //decompressTREs("/Users/fabiensanglard/Desktop/DATA/");
    
    //return 0;

//    listTRE();
//    return 0;
    
//    ExploreRootIFFS();
//    return 0;
    
    /*
    TreArchive archiveSound ;
    archiveSound.InitFromFile("SOUND.TRE");
    archiveSound.List(stdout);
    
    
    TreArchive archive ;
    archive.InitFromFile("GAMEFLOW.TRE");
    archive.List(stdout);
    
    RSImage screen;
    screen.Create("Screen",320, 200);
    
    RLECodex codex;
    size_t byteRead;
    codex.ReadImage(archive.GetData()+5824512, &screen, &byteRead);
    
    renderer.Init(320, 200);
    
    renderer.ShowWindow();
    renderer.Pause();
    while(renderer.IsPaused()){
        renderer.DrawImage(&screen, 1);
        renderer.Swap();
    }
    */
    
    //Render palette
    /*
    renderer.Init(512, 512);
    renderer.SetClearColor(255,0,255);
    renderer.Clear();
    renderer.ShowPalette(renderer.GetDefaultPalette());
    */
    
    
    /*
    SetBase("/Users/fabiensanglard/Desktop/ARENA.PAK.CONTENT/");
    PakArchive archiveMauritan ;
    archiveMauritan.InitFromFile("FILE1.TXT");
    archiveMauritan.Decompress("/Users/fabiensanglard/Desktop/ARENA.PAK.CONTENT/MIP_MAX/", "MIP_MAX");
    
    PakArchive f ;
    f.InitFromFile("FILE2.TXT");
    f.Decompress("/Users/fabiensanglard/Desktop/ARENA.PAK.CONTENT/MIP_MED/", "MIP_MED");
    
    PakArchive g ;
    g.InitFromFile("FILE3.TXT");
    g.Decompress("/Users/fabiensanglard/Desktop/ARENA.PAK.CONTENT/MIP_MIN/", "MIP_MIN");
    */
    
    /*
    PakArchive archiveMauritan ;
    archiveMauritan.InitFromFile("ARENA.PAK");
    archiveMauritan.Decompress("/Users/fabiensanglard/Desktop/", "TXT");
    */
    
    
    /*
    testShowAllTexturesPAK();
    return 0;
    */
    
    //WIP
    /*
    renderer.Init(640, 400);
    TreArchive tre;
    tre.InitFromFile("GAMEFLOW.TRE");
    
    TreEntry* pakToExplore = tre.GetEntryByName("..\\..\\DATA\\MIDGAMES\\MID1.PAK");
    
    PakArchive arch;
    arch.InitFromRAM("MID1.PAK",pakToExplore->data,pakToExplore->size);
    
    printf("MID1.PAK" " contains %lu entries\n.",arch.GetNumEntries());
    
    for(size_t i =0 ;i < arch.GetNumEntries() ; i++){
        
        PakEntry* entry = arch.GetEntry(i);
        PakArchive a;
        a.InitFromRAM("", entry->data, entry->size);
        showAllImageInArchive(&a);
    }
    return 0;
    */
    
    
    /*
    SCMainMenu mainMenu;
    mainMenu.Init();
    mainMenu.Run();
    return 0;
    */

    /* 
    SCDogFightMenu dogFightMenu;
    dogFightMenu.Init();
    dogFightMenu.Run();
    return 0;
    */
    
    /*
    SCObjectViewer viewer;
    viewer.Init();
    viewer.Run();
    return 0;
    */
    
    /*
    PakArchive archiveCanyon ;
    archiveCanyon.InitFromFile("CANYON.PAK");
    archiveCanyon.Decompress("/Users/fabiensanglard/Desktop/", "TXT");

    PakArchive archiveMauritan ;
    archiveMauritan.InitFromFile("MAURITAN.PAK");
    archiveMauritan.Decompress("/Users/fabiensanglard/Desktop/", "TXT");

    return 0;
    */
    
    
    
    
    //testShowAllTexturesPAK();
    
    SetBase("/Users/fabiensanglard/SC/SC/");
    RSArea* area = new RSArea();

    area->InitFromPAKFileName("ARENA.PAK");
    area->InitFromPAKFileName("ALASKA.PAK");
    area->InitFromPAKFileName("EUROPE.PAK");
    // // NOT A MAP !area.InitFromPAKFileName("MSFILES.PAK");
    area->InitFromPAKFileName("SANFRAN.PAK");
    area->InitFromPAKFileName("ANDMAL1.PAK");
    area->InitFromPAKFileName("CANYON.PAK");
    // // NOT A MAP !area.InitFromPAKFileName("MAPDATA.PAK");
    area->InitFromPAKFileName("QUEBEC.PAK");
    area->InitFromPAKFileName("TURKEY.PAK");
    area->InitFromPAKFileName("ANDMAL2.PAK");
    area->InitFromPAKFileName("EGYPT.PAK");
    area->InitFromPAKFileName("MAURITAN.PAK");
    area->InitFromPAKFileName("RHODEI.PAK");
    
    return EXIT_SUCCESS;
}