#ifndef SONGLIST_H_
#define SONGLIST_H_

class SongLoader;

struct ListEntry
{
	enum {
		Directory,
		Song
	} Kind;
	shared_ptr<void> Data;
	GString EntryName; 
};

class SongList
{
	SongList* mParent;
	std::vector<ListEntry> mChildren;

public:
	SongList (SongList *Parent = nullptr);
	~SongList();

	void AddNamedDirectory(mutex &loadMutex, SongLoader *Loader, Directory Dir, GString Name, bool VSRGActive, bool DotcurActive);
	void AddDirectory(mutex &loadMutex, SongLoader *Loader, Directory Dir, bool VSRGActive, bool DotcurActive);
	void AddVirtualDirectory(GString NewEntryName, Game::Song* List, int Count);
	void AddSong(shared_ptr<Game::Song> Song);

	// if false, it's a song
	bool IsDirectory(unsigned int Entry);
	shared_ptr<SongList> GetListEntry(unsigned int Entry);
	shared_ptr<Game::Song> GetSongEntry(unsigned int Entry);

	GString GetEntryTitle(unsigned int Entry);
	unsigned int GetNumEntries();

	void SortAlphabetically();
	bool HasParentDirectory();
	SongList* GetParentDirectory();
};

#endif