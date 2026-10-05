from person import Person


class Director(Person):
    """CHILD class #2 dari Person (Hierarchical Inheritance)."""

    def __init__(self, name: str, age: int, debut_year: int,
                 signature_style: str, awards_won: int):
        super().__init__(name, age, debut_year)
        self.__signature_style = signature_style
        self.__awards_won = awards_won

    # ---------- Getter ----------
    def get_signature_style(self) -> str:
        return self.__signature_style

    def get_awards_won(self) -> int:
        return self.__awards_won

    # ---------- Setter ----------
    def set_signature_style(self, signature_style: str) -> None:
        self.__signature_style = signature_style

    def set_awards_won(self, awards_won: int) -> None:
        self.__awards_won = awards_won

    def get_role(self) -> str:
        return "Director"

    def display_info(self) -> None:
        super().display_info()
        print(f"      Gaya Khas    : {self.__signature_style}")
        print(f"      Penghargaan  : {self.__awards_won} piala")
