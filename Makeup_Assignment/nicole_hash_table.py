# The purpose of this program is to set up a simple hash-map capable of simple storage and retrieval of words or phrases

class HashMap:
    map = []        # the map itself will be a list of lists
    buckets = 100   # specifies the number of buckets in the table when initialized

    # initializes hash-map as a list of empty lists in the quantity specified by self.buckets
    def __init__(self):
        # initialize map to a list of empty lists for use as buckets
        self.map = [[] for i in range(self.buckets)]

    # produces a repeatable hash code corresponding to an index in the hash-map outer list for use in searches
    def _hash_(self, term):
        hash_code = 0
        # the hash code used for this map is the sum of the uppercase ascii values of all characters in the string,
        # compressed into bucket quantity as in self.buckets - collisions will likely be common
        # hash code calculat
        return hash_code

    # private - conducts a search for a term in the hash-map, return binary True or False depending on if value is found
    def _search_(self, term):
        pass

    # public - conducts a search using _search_ and outputs a corresponding user message for a given search term
    def find(self, term):
        pass

    # inserts a term into the appropriate bucket if term is not found in a search to prevent redundant entries
    def insert(self, term):
        # does nothing if term is already an entry
        pass

    # removes a term from its bucket if present
    def remove(self, term):
        # does nothing if term is not an entry
        pass

    # prints all contents of all buckets to terminal
    def display(self):
        pass


# band names will be the stored entries in the map as they require the utmost speed in searches
band_list = ["Wilco", "King Gizzard and the Lizard Wizard", "Death From Above 1979", "Ween", "Queens of the Stone Age",
             "The White Stripes", "Jack White", "The Raconteurs", "The Dead Weather", "The Hentchmen", "Royal Blood",
             "Twin Peaks", "Black Lips", "Ty Segall", "The Beatles", "Led Zeppelin", "Dr. Dog", "Parquet Courts",
             "The Chats", "The Flaming Lips", "Eagles of Death Metal", "Mac DeMarco", "Thee Oh Sees", "Arctic Monkeys",
             "Neutral Milk Hotel", "The Mars Volta", "Them Crooked Vultures", "IDLES", "Iggy Pop", "The Stooges",
             "Rancid", "Streetlight Manifesto", "Reel Big Fish", "Less Than Jake", "FIDLAR", "Wavves", "Daughters",
             "SWANS", "Death Grips", "Pink Floyd", "Gogol Bordello", "The Rolling Stones", "Gorillaz", "Babe Rainbow",
             "Amyl and the Sniffers", "Stonefield", "Bob Dylan", "Creedence Clearwater Revival", "Screeching Weasel",
             "David Bowie", "The Velvet Underground", "Father John Misty", "Desert Sessions", "Johnny Cash"]

bands = HashMap()

# populate bands HashMap from band list
for i in range(len(band_list)):
    pass
    # uncomment the line below and delete the line above once your insertion function is finished
    # bands.insert(band_list[i])

bands.display()
