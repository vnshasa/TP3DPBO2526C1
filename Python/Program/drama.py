from actor import Actor
from director import Director
from episode import Episode
from person import Person
from writer import Writer


class Drama:
    """
    Kelas Drama.
    Aggregation : Director, Writer, dan Actor dibuat di luar Drama.
    Composition : Drama menyimpan object Episode yang dibuat menjadi bagian internal Drama.
    """

    def __init__(self, title: str, year: int, genre: str, broadcaster: str,
                 director: Director, writer: Writer):
        self.__title = title
        self.__year = year
        self.__genre = genre
        self.__broadcaster = broadcaster
        self.__director = director
        self.__writer = writer
        self.__cast: list[Actor] = []
        self.__episodes: list[Episode] = []

    # ---------- Getter ----------
    def get_title(self) -> str:
        return self.__title

    def get_year(self) -> int:
        return self.__year

    def get_genre(self) -> str:
        return self.__genre

    def get_broadcaster(self) -> str:
        return self.__broadcaster

    def get_director(self) -> Director:
        return self.__director

    def get_writer(self) -> Writer:
        return self.__writer

    def get_cast(self) -> list[Actor]:
        return self.__cast

    def get_episodes(self) -> list[Episode]:
        return list(self.__episodes)

    def get_total_episodes(self) -> int:
        return len(self.__episodes)

    # ---------- Setter ----------
    def set_title(self, title: str) -> None:
        self.__title = title

    def set_year(self, year: int) -> None:
        self.__year = year

    def set_genre(self, genre: str) -> None:
        self.__genre = genre

    def set_broadcaster(self, broadcaster: str) -> None:
        self.__broadcaster = broadcaster

    def set_director(self, director: Director) -> None:
        self.__director = director

    def set_writer(self, writer: Writer) -> None:
        self.__writer = writer

    def set_cast(self, cast: list[Actor]) -> None:
        self.__cast = cast

    def set_episodes(self, episodes: list[Episode]) -> None:
        # Composition: buat object Episode baru yang menjadi milik Drama.
        self.__episodes = []
        for ep in episodes:
            self.__episodes.append(Episode(
                ep.get_number(),
                ep.get_title(),
                ep.get_duration_minutes(),
                ep.get_viewer_rating()
            ))

    # ---------- Perhitungan ----------
    def get_total_duration(self) -> int:
        total = 0
        for ep in self.__episodes:
            total += ep.get_duration_minutes()
        return total

    def get_average_rating(self) -> float:
        if not self.__episodes:
            return 0.0
        total = 0.0
        for ep in self.__episodes:
            total += ep.get_viewer_rating()
        return total / len(self.__episodes)

    # ---------- Tampilan ----------
    def display(self) -> None:
        print("-" * 64)
        print(f"DRAMA: {self.__title}")
        print("-" * 64)
        print(f"  Tahun / Genre : {self.__year} / {self.__genre}")
        print(f"  Penyiar       : {self.__broadcaster}")
        print(f"  Episode       : {len(self.__episodes)} episode, total {self.get_total_duration()} menit")
        print(f"  Rata2 Rating  : {self.get_average_rating():.1f}%")

        credits: list[Person] = [self.__director, self.__writer, *self.__cast]

        print(f"\n  >> KREDIT (Sutradara, Penulis, Pemeran) - {len(credits)} orang")
        for person in credits:
            person.display_info()

        print("\n  >> DAFTAR EPISODE")
        print("    No | Judul                                              | Durasi    | Rating")
        print("    ---+----------------------------------------------------+-----------+-------")
        for ep in self.__episodes:
            ep.display()
        print()
