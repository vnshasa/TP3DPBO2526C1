from typing import Optional

from drama import Drama


class DramaCatalog:
    """
    Kelas DramaCatalog.
    Aggregation : catalog menyimpan referensi Drama yang dibuat di luar catalog.
    """

    def __init__(self, name: str):
        self.__name = name
        self.__dramas: list[Drama] = []

    # ---------- Getter ----------
    def get_name(self) -> str:
        return self.__name

    def get_dramas(self) -> list[Drama]:
        return self.__dramas

    # ---------- Setter ----------
    def set_name(self, name: str) -> None:
        self.__name = name

    def set_dramas(self, dramas: list[Drama]) -> None:
        self.__dramas = dramas

    def find_drama(self, title: str) -> Optional[Drama]:
        for drama in self.__dramas:
            if drama.get_title() == title:
                return drama
        return None

    def get_total_dramas(self) -> int:
        return len(self.__dramas)

    def get_total_episodes(self) -> int:
        total = 0
        for drama in self.__dramas:
            total += drama.get_total_episodes()
        return total

    def display_summary(self) -> None:
        print("No | Judul                        | Tahun | Genre                        | Eps | Avg Rating")
        print("---+------------------------------+-------+------------------------------+-----+-----------")
        for i, d in enumerate(self.__dramas, start=1):
            print(f"{i:>2} | {d.get_title():<28} | {d.get_year():>5} | {d.get_genre():<28} | "
                  f"{d.get_total_episodes():>3} | {d.get_average_rating():>9.1f}%")
        print()

    def display_all(self) -> None:
        print(f"KATALOG       : {self.__name}")
        print(f"Total Drama   : {self.get_total_dramas()}")
        print(f"Total Episode : {self.get_total_episodes()}\n")

        self.display_summary()
        for drama in self.__dramas:
            drama.display()
