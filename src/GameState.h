#ifndef GAMESTATE_H_
#define GAMESTATE_H_

class GameWindow;
struct GameParameters;

namespace dotcur
{
	class Song;
}

namespace VSRG
{
	struct Difficulty;
	class Song;
}

class SongDatabase;
class Image;
class ScoreKeeper7K;

struct lua_State;

namespace Game
{
	class Song;

class GameState
{
	GString CurrentSkin;
	SongDatabase* Database;

	Image* StageImage;
	Image* SongBG;
	shared_ptr<Game::Song> SelectedSong;
	shared_ptr<ScoreKeeper7K> SKeeper7K;
	shared_ptr<GameParameters> Params;
	map<GString, vector<GString>> Fallback; // 2nd is 1st's fallback

	bool FileExistsOnSkin(const char* Filename, const char* Skin);
public:

	GameState();
	GString GetSkinScriptFile(const char* Filename, const GString& Skin);
	shared_ptr<Game::Song> GetSelectedSongShared();
	GString GetFirstFallbackSkin();
	static GameState &GetInstance();
	void Initialize();

	void InitializeLua(lua_State *L);

	GString GetDirectoryPrefix();
	GString GetSkinPrefix();
	GString GetSkinPrefix(const GString &skin);
	GString GetScriptsDirectory();
	void SetSkin(GString NextSkin);
	Image* GetSkinImage(const GString& Image);
	bool SkinSupportsChannelCount(int Count);
	GString GetSkin();

	void SetSelectedSong(shared_ptr<Game::Song> Song);
	Game::Song *GetSelectedSong();
	void SetDifficultyIndex(uint32 DifficultyIndex);
	uint32 GetDifficultyIndex() const;

	// Note: Returning a shared_ptr causes lua to fail an assertion, since shared_ptr is not registered.
	ScoreKeeper7K* GetScorekeeper7K();
	void SetScorekeeper7K(shared_ptr<ScoreKeeper7K> Other);

	GString GetSkinFile(const GString &Name, const GString &Skin);
	GString GetSkinFile(const GString &Name);
	GString GetFallbackSkinFile(const GString &Name);

	SongDatabase* GetSongDatabase();
	static GameWindow* GetWindow();

	GameParameters* GetParameters();
};
}

using Game::GameState;


// This loads the meta only from the database.
void LoadSong7KFromDir( Directory songPath, std::vector<VSRG::Song*> &VecOut );

// This loads the whole of the song.
shared_ptr<VSRG::Song> LoadSong7KFromFilename(Directory Filename, Directory Prefix, VSRG::Song *Sng);

// Loads the whole of the song.
void LoadSongDCFromDir( Directory songPath, std::vector<dotcur::Song*> &VecOut );

#else
#error "GameState.h included twice."
#endif
