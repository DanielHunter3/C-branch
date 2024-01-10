Module Program

    Sub Main(args As String())
        Dim vec = {"+", "-", "*", "/", "^"}
        Dim x, y As Double
        Dim symbal As String

        Console.Write("Enter a first number: ")
        x = Console.ReadLine()

        Console.Write("Enter a symbal: ")
        symbal = Console.ReadLine()

        Dim is_bool = in_array(vec, symbal)
        If is_bool = False Then
            Exit Sub
        End If

        Console.Write("Enter a second number: ")
        y = Console.ReadLine()

        Dim result As New Math(x, y)
        Console.WriteLine($"Result: {[result].math_operations(symbal)}")

    End Sub

    Function in_array(vec() As String, str As String) As Boolean
        For Each i As String In vec
            If i = str Then
                Return True
            End If
        Next
        Return False
    End Function

End Module

Class Math

    Private x, y As Double

    Sub New(num1 As Double, num2 As Double)
        x = num1
        y = num2
    End Sub

    Public Function math_operations(str As String) As Double
        Select Case str
            Case "+"
                Return x + y
            Case "-"
                Return x - y
            Case "*"
                Return x * y
            Case "/"
                If y = 0.0 Then
                    Exit Function
                Else
                    Return x / y
                End If
            Case "^"
                Return x ^ y
        End Select
        Return 0.0
    End Function

End Class
